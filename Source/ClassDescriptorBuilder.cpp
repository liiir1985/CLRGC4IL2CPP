#include "il2cpp-config.h"

#if IL2CPP_GC_CORE
#include "ClassDescriptorBuilder.h"
#include "gcenv.h"

#include "gc.h"
#include "gcdesc.h"
#include "clrgc.h"
#include "tabledefs.h"
#include "object-internals.h"
#include "vm/Class.h"
#include "os/Mutex.h"

namespace clrgc
{
	namespace descriptor_builder
	{
		il2cpp::os::FastMutex mutex;

		inline BOOL IS_ALIGNED(size_t val, size_t alignment)
		{
			LIMITED_METHOD_CONTRACT;
			SUPPORTS_DAC;

			// alignment must be a power of 2 for this implementation to work (need modulo otherwise)
			IL2CPP_ASSERT(0 == (alignment & (alignment - 1)));
			return 0 == (val & (alignment - 1));
		}

		inline bool ShouldSkilField(FieldInfo& fi) 
		{
			if (fi.type->attrs & FIELD_ATTRIBUTE_STATIC)
				return true;
			switch (fi.type->type)
			{
			case IL2CPP_TYPE_STRING:
			case IL2CPP_TYPE_SZARRAY:
			case IL2CPP_TYPE_CLASS:
			case IL2CPP_TYPE_OBJECT:
			case IL2CPP_TYPE_ARRAY:
			case IL2CPP_TYPE_VAR:
			case IL2CPP_TYPE_MVAR:
			case IL2CPP_TYPE_GENERICINST:
				break;
			case IL2CPP_TYPE_VALUETYPE:
			{
				Il2CppClass* cls = il2cpp::vm::Class::FromIl2CppType(fi.type);
				if (!cls->has_references)
					return true;
				else
					return false;
			}
				break;
			default:
				return true;
			}
			return false;
		}

		size_t CalculateSeriesNum(Il2CppClass* klass)
		{
			int cnt = 0;
			for (int i = 0; i < klass->field_count; i++)
			{
				FieldInfo& fi = klass->fields[i];
				if (ShouldSkilField(fi))
					continue;
				if (fi.type->type == IL2CPP_TYPE_VALUETYPE)
				{
					Il2CppClass* cls = il2cpp::vm::Class::FromIl2CppType(fi.type);
					cnt += CalculateSeriesNum(cls);
				}
				else
					cnt++;
			}
			if (klass->parent != NULL && klass->parent->has_references)
			{
				cnt += CalculateSeriesNum(klass->parent);
			}
			IL2CPP_ASSERT(cnt);
			return cnt;
		}

		inline MethodTable* AllocNewMT(size_t seriesNum, uint16_t flags)
		{
			MethodTable* pMT;
			size_t seriesSize = CGCDesc::ComputeSize(seriesNum);
			size_t size = sizeof(MethodTable) + seriesSize;
			void* ptr = clrgc::AllocateInternal(size);
			pMT = (MethodTable*)((intptr_t)ptr + seriesSize);
			pMT->m_componentSize = 0;
			pMT->m_flags = flags;
			PTR_CGCDesc desc = CGCDesc::GetCGCDescFromMT(pMT);
			desc->Init(pMT, seriesNum);

			return pMT;
		}

		void GenerateMethodTable(Il2CppClass* klass)
		{
			IL2CPP_ASSERT(klass->gc_desc_precise == NULL);
			MethodTable* pMT = NULL;
			if (klass->rank > 0)
			{
				//IsArray
				if (klass->element_class->valuetype)
				{
					if (klass->element_class->has_references)
					{
						CGCDescSeries  *pSeries;
						MethodTable* pElemMT = MakeDescriptorForType(klass->element_class);
						// There must be only one series for value classes
						CGCDescSeries  *pByValueSeries = CGCDesc::GetCGCDescFromMT(pElemMT)->GetHighestSeries();

						// negative series has a special meaning, indicating a different form of GCDesc
						size_t nSeries = CGCDesc::GetCGCDescFromMT(pElemMT)->GetNumSeries();
						uint16_t flags = MTFlag_IsArray | MTFlag_ContainsPointers | MTFlag_HasComponentSize;
						if (klass->has_finalize)
							flags |= MTFlag_HasFinalizer;
						pMT = AllocNewMT(nSeries, flags);
						pMT->m_baseSize = AlignedSize(klass->instance_size);
						pMT->m_componentSize = klass->element_size;
						CGCDesc::GetCGCDescFromMT(pMT)->InitValueClassSeries(pMT, nSeries);

						pSeries = CGCDesc::GetCGCDescFromMT(pMT)->GetHighestSeries();

						// sort by offset
						size_t AllocSizeSeries;
						AllocSizeSeries = sizeof(CGCDescSeries*) * nSeries;
					
						CGCDescSeries** sortedSeries = (CGCDescSeries**)_alloca(AllocSizeSeries);
						int index;
						for (index = 0; index < nSeries; index++)
							sortedSeries[index] = &pByValueSeries[-index];

						// section sort
						for (int i = 0; i < nSeries; i++) {
							for (int j = i + 1; j < nSeries; j++)
								if (sortedSeries[j]->GetSeriesOffset() < sortedSeries[i]->GetSeriesOffset())
								{
									CGCDescSeries* temp = sortedSeries[i];
									sortedSeries[i] = sortedSeries[j];
									sortedSeries[j] = temp;
								}
						}

						// Offset of the first pointer in the array
						// This equals the offset of the first pointer if this were an array of entirely pointers, plus the offset of the
						// first pointer in the value class
						pSeries->SetSeriesOffset(kIl2CppSizeOfArray
							+ (sortedSeries[0]->GetSeriesOffset()) - sizeof(Il2CppObject));
						for (index = 0; index < nSeries; index++)
						{
							size_t numPtrsInBytes = sortedSeries[index]->GetSeriesSize()
								+ pElemMT->GetBaseSize();
							size_t currentOffset;
							size_t skip;
							currentOffset = sortedSeries[index]->GetSeriesOffset() + numPtrsInBytes;
							if (index != nSeries - 1)
							{
								skip = sortedSeries[index + 1]->GetSeriesOffset() - currentOffset;
							}
							else if (index == 0)
							{
								size_t bSize = pElemMT->GetBaseSize();
								skip = AlignedBytes(bSize) - numPtrsInBytes;
							}
							else
							{
								skip = sortedSeries[0]->GetSeriesOffset() + pElemMT->GetBaseSize()
									- ObjSizeOf(Il2CppObject) - currentOffset;
							}

							IL2CPP_ASSERT(!"Module::CreateArrayMethodTable() - unaligned GC info" || IS_ALIGNED(skip, sizeof(size_t)));

							unsigned short NumPtrs = (unsigned short)(numPtrsInBytes / sizeof(void*));
							IL2CPP_ASSERT(skip <= MAX_SIZE_FOR_VALUECLASS_IN_ARRAY && numPtrsInBytes <= MAX_PTRS_FOR_VALUECLASSS_IN_ARRAY);

							val_serie_item *val_item = &(pSeries->val_serie[-index]);

							val_item->set_val_serie_item(NumPtrs, (unsigned short)skip);
						}
					}
					else
					{
						size_t size = sizeof(MethodTable) + sizeof(size_t);
						void* ptr = clrgc::AllocateInternal(size);
						pMT = (MethodTable*)((intptr_t)ptr + sizeof(size_t));
						pMT->m_flags = MTFlag_Collectible | MTFlag_IsArray | MTFlag_HasComponentSize;
						if (klass->has_finalize)
							pMT->m_flags |= MTFlag_HasFinalizer;
						pMT->m_baseSize = AlignedSize(klass->instance_size);
						pMT->m_componentSize = klass->element_size;
						PTR_CGCDesc desc = CGCDesc::GetCGCDescFromMT(pMT);
						desc->Init(pMT, 0);
					}
				}
				else
				{
					uint16_t flags = MTFlag_ContainsPointers | MTFlag_IsArray | MTFlag_HasComponentSize;
					if (klass->has_finalize)
						flags |= MTFlag_HasFinalizer;
					pMT = AllocNewMT(1, flags);
					pMT->m_baseSize = AlignedSize(klass->instance_size);
					pMT->m_componentSize = klass->element_size;
					
					CGCDescSeries  *pSeries;
					pSeries = CGCDesc::GetCGCDescFromMT(pMT)->GetHighestSeries();

					pSeries->SetSeriesOffset(kIl2CppSizeOfArray);
					// For arrays, the size is the negative of the BaseSize (the GC always adds the total
					// size of the object, so what you end up with is the size of the data portion of the array)
					pSeries->SetSeriesSize(-((intptr_t)pMT->m_baseSize));
				}
				
			}
			else
			{
				if (klass->has_references)
				{
					size_t seriesNum = CalculateSeriesNum(klass);
					uint16_t flags = MTFlag_ContainsPointers;
					if (klass->has_finalize)
						flags |= MTFlag_HasFinalizer;
					pMT = AllocNewMT(seriesNum, flags);
					pMT->m_baseSize = AlignedSize(klass->instance_size);
					pMT->m_componentSize = 0;
					PTR_CGCDescSeries series = CGCDesc::GetCGCDescFromMT(pMT)->GetLowestSeries();

					int i = 0;
					Il2CppClass* cur = klass;
					while (cur && cur->has_references)
					{
						for (int j = cur->field_count - 1; j >= 0; j--)
						{
							FieldInfo& fi = cur->fields[j];
							if (ShouldSkilField(fi))
								continue;
							CGCDescSeries& cur = series[i];
							i++;
							cur.SetSeriesOffset(fi.offset);
							cur.SetSeriesCount(1);
							cur.seriessize -= pMT->m_baseSize;
						}
						cur = cur->parent;
					}
					IL2CPP_ASSERT(i == seriesNum);
				}
				else
				{
					size_t size = sizeof(MethodTable) + sizeof(size_t);
					void* ptr = clrgc::AllocateInternal(size);
					pMT = (MethodTable*)((intptr_t)ptr + sizeof(size_t));
					pMT->m_flags = MTFlag_Collectible;
					if (klass->has_finalize)
						pMT->m_flags |= MTFlag_HasFinalizer;
					pMT->m_baseSize = AlignedSize(klass->instance_size);
					pMT->m_componentSize = 0;
					PTR_CGCDesc desc = CGCDesc::GetCGCDescFromMT(pMT);
					desc->Init(pMT, 0);
				}
			}
			
			IL2CPP_ASSERT(pMT);
			klass->gc_desc_precise = pMT;
		}

		MethodTable * MakeDescriptorForType(Il2CppClass * klass)
		{
			if (klass->gc_desc_precise)
				return (MethodTable*)klass->gc_desc_precise;
			mutex.Lock();
			//It can be retrived from a previous lock operation
			if (klass->gc_desc_precise)
				return (MethodTable*)klass->gc_desc_precise;
			GenerateMethodTable(klass);
			mutex.Unlock();
			return (MethodTable*)klass->gc_desc_precise;
		}
	}
}


#endif