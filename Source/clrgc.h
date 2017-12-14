#pragma once

#include "gc/GarbageCollector.h"
#include <vector>
struct Il2CppClass;
#define ObjSizeOf(c)    (sizeof(c) + sizeof(ObjHeader))
#define AlignedSize(c)  max(c + sizeof(ObjHeader), MIN_OBJECT_SIZE)
#define AlignedBytes(c) ((c + 3) & (~3))
namespace clrgc
{
	int Initialize();

	bool RegisterThread(void* basePtr);

	bool UnRegisterThread();

	void* AllocateFixed(size_t size);

	void FreeFixed(void* addr);

	void* AllocateObject(size_t size, Il2CppClass* klass);

	void* AllocateFree(size_t size, Il2CppClass* klass);

	void* AllocateInternal(size_t size);

	bool IsValidInternalMemory(void* ptr);

	void WriteBarrier(void** dst, void* ref);

	void RunFinalizer();

	void RegisterFinalizer(Il2CppObject* obj, il2cpp::gc::GarbageCollector::FinalizerCallback callback);

	void* AquireStrongHandle(Il2CppObject* obj, bool pinned);

	void ReleaseStrongHandle(void* handle, bool pinned);

	void InitBoehm();

	void InitBoehmThread();

	void RegisterThreadBoehm(void* baseptr);

	void UnregisterThreadBoehm();

	intptr_t approx_sp(void);

	intptr_t GetStackPointerAndRegisters(bool isSelf, void* handle, std::vector<uintptr_t>& registers);
}