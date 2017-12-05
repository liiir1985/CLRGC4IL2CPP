#include "ClassDescriptorBuilder.h"
#include "gcenv.h"

#include "gc.h"
#include "gcdesc.h"
#include "clrgc.h"
#include "tabledefs.h"
#include "object-internals.h"

namespace clrgc
{
	namespace descriptor_builder
	{
		struct Descriptor
		{
		
			CGCDescSeries* m_series;
			// GCDesc
			size_t m_numSeries;

			// The actual methodtable
			MethodTable m_MT;
			
			static void Initialize(Descriptor& desc, void* addr, int seriesCnt)
			{
				desc.m_MT = *(MethodTable*)addr;
				desc.m_numSeries = *(size_t*)((intptr_t)addr - sizeof(size_t));
				desc.m_series = (CGCDescSeries*)((intptr_t)addr - sizeof(size_t) - sizeof(CGCDescSeries) * desc.m_numSeries);
			}

		};

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
				cnt++;
			}
			return cnt;
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
						IL2CPP_ASSERT(IL2CPP_E_NOTIMPL);
					}
					else
					{
						size_t size = sizeof(MethodTable) + sizeof(size_t);
						void* ptr = malloc(size);
						pMT = (MethodTable*)((intptr_t)ptr + sizeof(size_t));
						pMT->m_flags = MTFlag_Collectible;
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
					size_t seriesNum = 1;
					size_t seriesSize = CGCDesc::ComputeSize(seriesNum);
					size_t size = sizeof(MethodTable) + seriesSize;
					void* ptr = malloc(size);
					pMT = (MethodTable*)((intptr_t)ptr + seriesNum);
					pMT->m_flags = MTFlag_Collectible | MTFlag_ContainsPointers;
					if (klass->has_finalize)
						pMT->m_flags |= MTFlag_HasFinalizer;
					pMT->m_baseSize = AlignedSize(klass->instance_size);
					pMT->m_componentSize = klass->element_size;
					PTR_CGCDesc desc = CGCDesc::GetCGCDescFromMT(pMT);
					desc->Init(pMT, seriesNum);
					
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
					size_t seriesSize = CGCDesc::ComputeSize(seriesNum);
					size_t size = sizeof(MethodTable) + seriesSize;
					void* ptr = malloc(size);
					pMT = (MethodTable*)((intptr_t)ptr + seriesNum);
					pMT->m_flags = MTFlag_Collectible | MTFlag_ContainsPointers;
					if (klass->has_finalize)
						pMT->m_flags |= MTFlag_HasFinalizer;
					pMT->m_baseSize = AlignedSize(klass->instance_size);
					pMT->m_componentSize = 0;
					PTR_CGCDesc desc = CGCDesc::GetCGCDescFromMT(pMT);
					desc->Init(pMT, seriesNum);
					PTR_CGCDescSeries series = desc->GetHighestSeries();

					int i = 0;
					for (int j = 0; j < klass->field_count; j++)
					{
						FieldInfo& fi = klass->fields[j];
						if (ShouldSkilField(fi))
							continue;
						CGCDescSeries& cur = series[-i];
						i++;
						cur.SetSeriesOffset(fi.offset);
						cur.SetSeriesCount(1);
						cur.seriessize -= pMT->m_baseSize;
					}

				}
				else
				{
					size_t size = sizeof(MethodTable) + sizeof(size_t);
					void* ptr = malloc(size);
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
			
			GenerateMethodTable(klass);
			return (MethodTable*)klass->gc_desc_precise;
		}
	}
}


