
#include "il2cpp-api.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "private\gc_priv.h"
#ifdef __cplusplus
}
#endif
#include "gc_mark.h"
#include "clrgc.h"
#include "os/Thread.h"

namespace clrgc
{
	intptr_t approx_sp(void)
	{
		volatile word sp;
		sp = (word)&sp;
		/* Also force stack to grow if necessary. Otherwise the */
		/* later accesses might cause the kernel to think we're */
		/* doing something wrong.                               */
		return((intptr_t)sp);
		/* GNU C: alternatively, we may return the value of     */
		/*__builtin_frame_address(0).                           */
	}

	void InitBoehm()
	{
		GC_INIT();
	}
	void InitBoehmThread()
	{
		GC_allow_register_threads();
	}

	void RegisterThreadBoehm(void* baseptr)
	{
#if defined(GC_THREADS)
		struct GC_stack_base sb;
		int res;

		res = GC_get_stack_base(&sb);
		if (res != GC_SUCCESS)
		{
			sb.mem_base = baseptr;
#ifdef __ia64__
			/* Can't determine the register stack bounds */
			IL2CPP_ASSERT(false && "mono_gc_register_thread failed ().");
#endif
		}
		res = GC_register_my_thread(&sb);
		if ((res != GC_SUCCESS) && (res != GC_DUPLICATE))
		{
			IL2CPP_ASSERT(false && "GC_register_my_thread () failed.");			
		}
#endif
	}

	void UnregisterThreadBoehm()
	{
#if defined(GC_THREADS)
		int res;

		res = GC_unregister_my_thread();
		if (res != GC_SUCCESS)
			IL2CPP_ASSERT(false && "GC_unregister_my_thread () failed.");

#else		
#endif
	}
}
