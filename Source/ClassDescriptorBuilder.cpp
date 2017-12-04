#include "ClassDescriptorBuilder.h"
#include "gcenv.h"

#include "gc.h"
#include "gcdesc.h"
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

		MethodTable * MakeDescriptorForType(Il2CppClass * klass)
		{
			if (klass->gc_desc_precise)
				return (MethodTable*)klass->gc_desc_precise;

			
			return nullptr;
		}
	}
}


