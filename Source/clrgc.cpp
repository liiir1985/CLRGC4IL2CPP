
#include "common.h"
#include <unordered_map>
#include "gcenv.h"

#include "gc.h"
#include "objecthandle.h"

#include "gcdesc.h"
#include "clrgc.h"
#include "ClassDescriptorBuilder.h"
#include "object-internals.h"

namespace WKS
{
	void GCLog22(const char *fmt, ...)
	{
		va_list valist;
		va_start(valist, fmt);

		printf(fmt, valist);
		va_end(valist);

		printf("\n");

	}
}
namespace clrgc
{
	inline Object* AllocateFree(MethodTable* pMT, size_t size)
	{
		alloc_context * acontext = GetThread()->GetAllocContext();
		Object * pObject;

		IL2CPP_ASSERT(size >= pMT->GetBaseSize());

		uint8_t* result = acontext->alloc_ptr;
		uint8_t* advance = result + size;
		if (advance <= acontext->alloc_limit)
		{
			acontext->alloc_ptr = advance;
			pObject = (Object *)result;
		}
		else
		{
			pObject = g_theGCHeap->Alloc(acontext, size, 0);
			if (pObject == NULL)
				return NULL;
		}

		pObject->RawSetMethodTable(pMT);

		return pObject;
	}

	inline Object * AllocateObject(MethodTable * pMT)
	{
		size_t size = pMT->GetBaseSize();

		return AllocateFree(pMT, size);
	}

	
#if defined(BIT64)
	// Card byte shift is different on 64bit.
#define card_byte_shift     11
#else
#define card_byte_shift     10
#endif

#define card_byte(addr) (((size_t)(addr)) >> card_byte_shift)

	inline void ErectWriteBarrier(Object ** dst, Object * ref)
	{
		// if the dst is outside of the heap (unboxed value classes) then we
		//      simply exit
		if (((uint8_t*)dst < g_gc_lowest_address) || ((uint8_t*)dst >= g_gc_highest_address))
			return;

		// volatile is used here to prevent fetch of g_card_table from being reordered 
		// with g_lowest/highest_address check above. See comment in code:gc_heap::grow_brick_card_tables.
		uint8_t* pCardByte = (uint8_t *)*(volatile uint8_t **)(&g_gc_card_table) + card_byte((uint8_t *)dst);
		if (*pCardByte != 0xFF)
			*pCardByte = 0xFF;
	}

	void WriteBarrier(Object ** dst, Object * ref)
	{
		*dst = ref;
		ErectWriteBarrier(dst, ref);
	}

	struct FreeSizeObject_MethodTable
	{
		// GCDesc
		size_t m_numSeries = 0;

		// The actual methodtable
		MethodTable m_MT;
	};

	class FixedObject : public Object
	{
	private:
		OBJECTHANDLE handle;
	public:
		void AccuireHandle()
		{
			if (handle == NULL)
			{
				handle = HndCreateHandle(g_HandleTableMap.pBuckets[0]->pTable[GetCurrentThreadHomeHeapNumber()], HNDTYPE_PINNED, this);
			}
		}

		void ReleaseHandle()
		{
			if (handle)
			{
				HndDestroyHandle(HndGetHandleTable(handle), HNDTYPE_PINNED, handle);
			}
		}
	};
	class FreeSizeObject : public FixedObject
	{
	private:
		int content;
	public:		
		void* GetAddress()
		{
			return &content;
		}

		static FreeSizeObject* GetObjectFromAddress(void* address) 
		{
			return (FreeSizeObject*)((intptr_t)address - offsetof(FreeSizeObject, content));
		}
	};

	static FreeSizeObject_MethodTable fDescMethodTable;

	#define CalculateTypeSize(t,addition) max(sizeof(t)+sizeof(ObjHeader) + addition, MIN_OBJECT_SIZE)

	
	extern "C" HRESULT GC_Initialize(IGCToCLR* clrToGC, IGCHeap** gcHeap, IGCHandleManager** gcHandleManager, GcDacVars* gcDacVars);

	int clrgc::Initialize()
	{
		//
		// Initialize system info
		//
		if (!GCToOSInterface::Initialize())
		{
			return -1;
		}

		// 
		// Initialize free object methodtable. The GC uses a special array-like methodtable as placeholder
		// for collected free space.
		//
		static MethodTable freeObjectMT;
		freeObjectMT.InitializeFreeObject();
		g_gc_pFreeObjectMethodTable = &freeObjectMT;

		//
		// Initialize GC heap
		//
		GcDacVars dacVars;
		IGCHeap *pGCHeap;
		IGCHandleManager *pGCHandleManager;
		if (GC_Initialize(nullptr, &pGCHeap, &pGCHandleManager, &dacVars) != S_OK)
		{
			return -1;
		}

		if (FAILED(pGCHeap->Initialize()))
			return -1;

		//
		// Initialize handle manager
		//
		if (!pGCHandleManager->Initialize())
			return -1;

		fDescMethodTable.m_MT.m_baseSize = AlignedSize(ObjSizeOf(FreeSizeObject));
		fDescMethodTable.m_MT.m_flags = 0;
		fDescMethodTable.m_MT.m_componentSize = 0;
		fDescMethodTable.m_numSeries = 0;
		
		ThreadStore::AttachCurrentThread();
		return 0;
	}

	bool RegisterThread(void * basePtr)
	{
		ThreadStore::AttachCurrentThread();
		return true;
	}

	bool UnRegisterThread()
	{
		return false;
	}

	void* clrgc::AllocateFixed(size_t size)
	{
		
		FreeSizeObject* obj = (FreeSizeObject*)AllocateObject(&fDescMethodTable.m_MT);
		obj->AccuireHandle();
		return obj->GetAddress();
	}

	void clrgc::FreeFixed(void* addr)
	{
		FreeSizeObject* obj = FreeSizeObject::GetObjectFromAddress(addr);

		obj->ReleaseHandle();
	}

	void* clrgc::AllocateObject(size_t size, Il2CppClass* klass)
	{
		MethodTable* tbl = clrgc::descriptor_builder::MakeDescriptorForType(klass);
		size_t alocSize = AlignedSize(size);
		Il2CppObject* obj;
		if (klass->rank > 0)
		{
			obj = (Il2CppObject*)AllocateFree(tbl, alocSize);
		}
		else 
		{
			IL2CPP_ASSERT(alocSize == tbl->GetBaseSize());
			obj = (Il2CppObject*)AllocateObject(tbl);
		}
		return obj;
	}
	void * AllocateFree(size_t size, Il2CppClass * klass)
	{
		MethodTable* tbl = clrgc::descriptor_builder::MakeDescriptorForType(klass);

		Il2CppObject* obj = (Il2CppObject*)AllocateFree(tbl, AlignedSize(size));
		return obj;
	}
}