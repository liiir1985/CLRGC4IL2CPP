#include "il2cpp-config.h"

#if IL2CPP_GC_CORE

#include <stdint.h>
#include "gc_wrapper.h"
#include "GarbageCollector.h"
#include "vm/Profiler.h"
#include "vm/Thread.h"
#include "object-internals.h"
#include "clrgc.h"

static bool s_GCInitialized = false;

#if IL2CPP_ENABLE_PROFILER
using il2cpp::vm::Profiler;
static void on_gc_event(Il2CppGCEvent eventType);
static void on_heap_resize(int64_t newSize);
#endif

void
il2cpp::gc::GarbageCollector::Initialize()
{
	if (s_GCInitialized)
		return;

	int res = clrgc::Initialize();

	IL2CPP_ASSERT(res == 0);
	// This tells the GC that we are not scanning dynamic library data segments and that
	// the GC tracked data structures need ot be manually pushed and marked.
	// Call this before GC_INIT since the initialization logic uses this value.
	/*GC_set_no_dls(1);

#if IL2CPP_ENABLE_PROFILER
	GC_set_on_event(&on_gc_event);
	GC_set_on_heap_resize(&on_heap_resize);
#endif

	GC_INIT();
#if defined(GC_THREADS)
	GC_set_finalize_on_demand(1);
	GC_set_finalizer_notifier(&il2cpp::gc::GarbageCollector::NotifyFinalizers);
	// We need to call this if we want to manually register threads, i.e. GC_register_my_thread
	GC_allow_register_threads();
#endif
#ifdef GC_GCJ_SUPPORT
	GC_init_gcj_malloc(0, NULL);
#endif
*/
	s_GCInitialized = true;
}

int32_t
il2cpp::gc::GarbageCollector::GetCollectionCount(int32_t generation)
{
	return 0;
	//return (int32_t)GC_get_gc_no();
}

int32_t
il2cpp::gc::GarbageCollector::GetMaxGeneration()
{
	return 0;
}

void
il2cpp::gc::GarbageCollector::Collect(int maxGeneration)
{
	//GC_gcollect();
}

int32_t
il2cpp::gc::GarbageCollector::CollectALittle()
{
	return 0;
	//return GC_collect_a_little();
}

int64_t
il2cpp::gc::GarbageCollector::GetUsedHeapSize(void)
{
	return 0;
	//return GC_get_heap_size() - GC_get_free_bytes();
}

int64_t
il2cpp::gc::GarbageCollector::GetAllocatedHeapSize(void)
{
	return 0;
	//return GC_get_heap_size();
}

void
il2cpp::gc::GarbageCollector::Disable()
{
	//GC_disable();
}

void
il2cpp::gc::GarbageCollector::Enable()
{
	//GC_enable();
}

bool
il2cpp::gc::GarbageCollector::RegisterThread(void *baseptr)
{
	return clrgc::RegisterThread(baseptr);
}

bool
il2cpp::gc::GarbageCollector::UnregisterThread()
{
	return clrgc::UnRegisterThread();
}

il2cpp::gc::GarbageCollector::FinalizerCallback il2cpp::gc::GarbageCollector::RegisterFinalizerWithCallback(Il2CppObject* obj, FinalizerCallback callback)
{
	/*FinalizerCallback oldCallback;
	void* oldData;
	GC_REGISTER_FINALIZER_NO_ORDER((char*)obj, callback, NULL, &oldCallback, &oldData);
	IL2CPP_ASSERT(oldData == NULL);
	return oldCallback;*/
	return NULL;
}

void
il2cpp::gc::GarbageCollector::AddWeakLink(void **link_addr, Il2CppObject *obj, bool track)
{
	
	/* libgc requires that we use HIDE_POINTER... */
	/**link_addr = (void*)GC_HIDE_POINTER(obj);
	// need this since our strings are not real objects
	if (GC_is_heap_ptr(obj))
		GC_GENERAL_REGISTER_DISAPPEARING_LINK(link_addr, obj);
		*/
}

void
il2cpp::gc::GarbageCollector::RemoveWeakLink(void **link_addr)
{
	/*Il2CppObject*  obj = GarbageCollector::GetWeakLink(link_addr);
	if (GC_is_heap_ptr(obj))
		GC_unregister_disappearing_link(link_addr);
	*link_addr = NULL;*/
}

static void*
RevealLink(void* link_addr)
{
	/*void **link_a = (void**)link_addr;
	return GC_REVEAL_POINTER(*link_a);*/
}

Il2CppObject*
il2cpp::gc::GarbageCollector::GetWeakLink(void **link_addr)
{
	/*Il2CppObject *obj = (Il2CppObject*)GC_call_with_alloc_lock(RevealLink, link_addr);
	if (obj == (Il2CppObject*)-1)
		return NULL;
	return obj;*/
	return NULL;
}

void*
il2cpp::gc::GarbageCollector::MakeDescriptorForObject(size_t *bitmap, int numbits)
{
	return GC_NO_DESCRIPTOR;
}

void* il2cpp::gc::GarbageCollector::MakeDescriptorForString()
{
	return GC_NO_DESCRIPTOR;
}

void* il2cpp::gc::GarbageCollector::MakeDescriptorForArray()
{
	return GC_NO_DESCRIPTOR;
}

void il2cpp::gc::GarbageCollector::StopWorld()
{
	//GC_stop_world_external();
}

void il2cpp::gc::GarbageCollector::StartWorld()
{
	//GC_start_world_external();
}

void*
il2cpp::gc::GarbageCollector::AllocateFixed(size_t size, void *descr)
{
	// Note that we changed the implementation from mono.
	// In our case, we expect that
	// a) This memory will never be moved
	// b) This memory will be scanned for references
	// c) This memory will remain 'alive' until explicitly freed
	// GC_MALLOC_UNCOLLECTABLE fulfills all these requirements
	// It does not accept a descriptor, but there was only one
	// or two places in mono that pass a descriptor to this routine
	// and we can or will support those use cases in a different manner.
	IL2CPP_ASSERT(!descr);

	return clrgc::AllocateFixed(size);
}

void
il2cpp::gc::GarbageCollector::FreeFixed(void* addr)
{
	clrgc::FreeFixed(addr);
}

Il2CppObject* il2cpp::gc::GarbageCollector::AllocateObject(size_t size, Il2CppClass* klass)
{
	return (Il2CppObject*)clrgc::AllocateObject(size, klass);
}

Il2CppObject* il2cpp::gc::GarbageCollector::AllocateFree(size_t size, Il2CppClass* klass)
{
	return (Il2CppObject*)clrgc::AllocateFree(size, klass);
}

int32_t
il2cpp::gc::GarbageCollector::InvokeFinalizers()
{
	return 0;
	//return (int32_t)GC_invoke_finalizers();
}

bool
il2cpp::gc::GarbageCollector::HasPendingFinalizers()
{
	return 0;
	//return GC_should_invoke_finalizers() != 0;
}

#if IL2CPP_ENABLE_PROFILER

void on_gc_event(Il2CppGCEvent eventType)
{
	Profiler::GCEvent((Il2CppGCEvent)eventType);
}

void on_heap_resize(int64_t newSize)
{
	Profiler::GCHeapResize((int64_t)newSize);
}

#endif // IL2CPP_ENABLE_PROFILER

void il2cpp::gc::GarbageCollector::ForEachHeapSection(void* user_data, HeapSectionCallback callback)
{
	//GC_foreach_heap_section(user_data, callback);
}

size_t il2cpp::gc::GarbageCollector::GetSectionCount()
{
	return 0;
	//return GC_get_heap_section_count();
}

void* il2cpp::gc::GarbageCollector::CallWithAllocLockHeld(GCCallWithAllocLockCallback callback, void* user_data)
{
	return 0;
	//return GC_call_with_alloc_lock(callback, user_data);
}

#endif
