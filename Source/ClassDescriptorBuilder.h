#pragma once

#include "class-internals.h"
#include "gcenv.base.h"
namespace clrgc
{
	namespace descriptor_builder
	{
		MethodTable* MakeDescriptorForType(Il2CppClass* klass);
	}
}