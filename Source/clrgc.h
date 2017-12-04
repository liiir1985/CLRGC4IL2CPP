#pragma once

struct Il2CppClass;

namespace clrgc
{
	int Initialize();

	void* AllocateFixed(size_t size);

	void FreeFixed(void* addr);

	void* AllocateObject(size_t size, Il2CppClass* klass);
}