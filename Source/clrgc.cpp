
#include "common.h"
#include <unordered_map>
#include "gcenv.h"

#include "gc.h"
#include "objecthandle.h"

#include "gcdesc.h"
#include "clrgc.h"

namespace clrgc
{
	Object * AllocateObject(MethodTable * pMT)
	{
		alloc_context * acontext = GetThread()->GetAllocContext();
		Object * pObject;

		size_t size = pMT->GetBaseSize();

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

	struct FreeSizeDescriptor_MethodTable
	{
		// GCDesc
		size_t m_numSeries = 0;

		// The actual methodtable
		MethodTable m_MT;
	};

	class FixedObject : Object
	{
	private:
		OBJECTHANDLE handle;
	public:
		void AccuireHandle()
		{
			if (handle == NULL)
			{
				handle = HndCreateHandle(g_HandleTableMap.pBuckets[0]->pTable[GetCurrentThreadHomeHeapNumber()], HNDTYPE_DEFAULT, this);
			}
		}

		void ReleaseHandle()
		{
			if (handle)
			{
				HndDestroyHandle(HndGetHandleTable(handle), HNDTYPE_DEFAULT, handle);
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

	FreeSizeDescriptor_MethodTable fDescMethodTable;

	class FreeSizeDescriptor : public FixedObject
	{
	private:
		FreeSizeObject_MethodTable m_MT;
		int refCount;
		
	public:
		FreeSizeObject_MethodTable& GetDescriptor()
		{
			return m_MT;
		}

		void SetDescriptor(FreeSizeObject_MethodTable& mt)
		{
			m_MT = mt;
		}

		void AddRef()
		{
			refCount++;
		}

		void RemoveRef()
		{
			refCount--;
			ASSERT(refCount >= 0);
		}

		bool CanRelease()
		{
			return refCount <= 0;
		}
	};

	std::unordered_map<size_t, FreeSizeDescriptor*> descriptorMap;	

	#define CalculateTypeSize(t,addition) max(sizeof(t)+sizeof(ObjHeader) + addition, MIN_OBJECT_SIZE)

	inline FreeSizeDescriptor* GetDescriptorForFreeSizeObject(size_t size)
	{
		size = CalculateTypeSize(FreeSizeObject, size - sizeof(int));
		std::unordered_map<size_t, FreeSizeDescriptor*>::iterator it = descriptorMap.find(size);
		FreeSizeDescriptor* found;
		if (it != descriptorMap.end()) 
		{
			found = it->second;
		}
		else 
		{
			if (fDescMethodTable.m_MT.m_baseSize <= 0)
			{
				// Add padding as necessary. GC requires the object size to be at least MIN_OBJECT_SIZE.
				fDescMethodTable.m_MT.m_baseSize = CalculateTypeSize(FreeSizeDescriptor, 0);
				fDescMethodTable.m_MT.m_componentSize = 0;    // Array component size
				fDescMethodTable.m_MT.m_flags = 0;
			}

			found = (FreeSizeDescriptor*)AllocateObject(&fDescMethodTable.m_MT);
			FreeSizeObject_MethodTable mt;
			mt.m_MT.m_baseSize = size;
			found->SetDescriptor(mt);
			found->AccuireHandle();
		}

		return found;
	}

	void* clrgc::AllocateFixed(size_t size)
	{
		FreeSizeDescriptor* descriptor = GetDescriptorForFreeSizeObject(size);
		descriptor->AddRef();

		FreeSizeObject* obj = (FreeSizeObject*)AllocateObject(&descriptor->GetDescriptor().m_MT);
		obj->AccuireHandle();
		return obj->GetAddress();
	}
}