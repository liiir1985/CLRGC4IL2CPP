#pragma once

struct Il2CppClass;
#define ObjSizeOf(c)    (sizeof(c) + sizeof(ObjHeader))
#define AlignedSize(c)  max(c + sizeof(ObjHeader), MIN_OBJECT_SIZE)
namespace clrgc
{
	int Initialize();

	bool RegisterThread(void* basePtr);

	bool UnRegisterThread();

	void* AllocateFixed(size_t size);

	void FreeFixed(void* addr);

	void* AllocateObject(size_t size, Il2CppClass* klass);

	void* AllocateFree(size_t size, Il2CppClass* klass);
}