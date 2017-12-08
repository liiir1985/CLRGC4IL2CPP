#include "il2cpp-config.h"
#if IL2CPP_GC_CORE
// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

#include "env/common.h"

#include "windows.h"

#include "gcenv.h"
#include "gc.h"
#include "il2cpp-api.h"
#include "il2cpp-api-types.h"
#include "os/Thread.h"
#include "os/Mutex.h"
#include "gc/GarbageCollector.h"
#include "vm/Thread.h"
#include "object-internals.h"
#include "il2cpp-metadata.h"
#include "clrgc.h"

MethodTable * g_pFreeObjectMethodTable;

int32_t g_TrapReturningThreads;

EEConfig * g_pConfig;

gc_alloc_context g_global_alloc_context;

/*bool CLREventStatic::CreateManualEventNoThrow(bool bInitialState)
{
    m_hEvent = CreateEventW(NULL, TRUE, bInitialState, NULL);
    m_fInitialized = true;

    return IsValid();
}

bool CLREventStatic::CreateAutoEventNoThrow(bool bInitialState)
{
    m_hEvent = CreateEventW(NULL, FALSE, bInitialState, NULL);
    m_fInitialized = true;

    return IsValid();
}

bool CLREventStatic::CreateOSManualEventNoThrow(bool bInitialState)
{
    m_hEvent = CreateEventW(NULL, TRUE, bInitialState, NULL);
    m_fInitialized = true;

    return IsValid();
}

bool CLREventStatic::CreateOSAutoEventNoThrow(bool bInitialState)
{
    m_hEvent = CreateEventW(NULL, FALSE, bInitialState, NULL);
    m_fInitialized = true;

    return IsValid();
}

void CLREventStatic::CloseEvent()
{
    if (m_fInitialized && m_hEvent != INVALID_HANDLE_VALUE)
    {
        CloseHandle(m_hEvent);
        m_hEvent = INVALID_HANDLE_VALUE;
    }
}

bool CLREventStatic::IsValid() const
{
    return m_fInitialized && m_hEvent != INVALID_HANDLE_VALUE;
}

bool CLREventStatic::Set()
{
    if (!m_fInitialized)
        return false;
    return !!SetEvent(m_hEvent);
}

bool CLREventStatic::Reset()
{
    if (!m_fInitialized)
        return false;
    return !!ResetEvent(m_hEvent);
}

uint32_t CLREventStatic::Wait(uint32_t dwMilliseconds, bool bAlertable)
{
    DWORD result = WAIT_FAILED;

    if (m_fInitialized)
    {
        bool        disablePreemptive = false;
        Thread *    pCurThread = GetThread();

        if (NULL != pCurThread)
        {
            if (GCToEEInterface::IsPreemptiveGCDisabled(pCurThread))
            {
                GCToEEInterface::EnablePreemptiveGC(pCurThread);
                disablePreemptive = true;
            }
        }

        result = WaitForSingleObjectEx(m_hEvent, dwMilliseconds, bAlertable);

        if (disablePreemptive)
        {
            GCToEEInterface::DisablePreemptiveGC(pCurThread);
        }
    }

    return result;
}*/


__declspec(thread) Thread * pCurrentThread;

inline bool dbgOnly_IsSpecialEEThread()
{
    return true;
}

Thread * GetThread()
{
    return pCurrentThread;
}

Thread * g_pThreadList = NULL;
il2cpp::os::FastMutex mutex;

Thread * ThreadStore::GetThreadList(Thread * pThread)
{
    if (pThread == NULL)
        return g_pThreadList;

    return pThread->m_pNext;
}

extern const Il2CppGlobalMetadataHeader* s_GlobalMetadataHeader;
extern Il2CppClass** s_TypeInfoDefinitionTable;

void ThreadStore::AttachCurrentThread(void* baseptr)
{
    mutex.Lock();
    if (pCurrentThread)
    {
        pCurrentThread->SetBasePointer((intptr_t)baseptr);
        mutex.Unlock();
        return;
    }
    il2cpp::os::Thread* il2cppThread = il2cpp::os::Thread::GetOrCreateCurrentThread();

    Thread * pThread = new Thread();
    pThread->GetAllocContext()->init();
    pThread->SetNativeThread(il2cppThread);
    pThread->SetBasePointer((intptr_t)baseptr);
    pCurrentThread = pThread;

    pThread->m_pNext = g_pThreadList;
    g_pThreadList = pThread;
    mutex.Unlock();
}

#define INTPTR_INC(p) p = p + sizeof(uintptr_t)
#define INTPTR_DEC(p) p = p - sizeof(uintptr_t)
#define IS_GC_HEAP_ADDR(addr) addr <= (PTR_Object)g_gc_highest_address && addr >= (PTR_Object)g_gc_lowest_address
#define IS_VALID_KLASS(klass) klass >= s_TypeInfoDefinitionTable && klass <= (s_TypeInfoDefinitionTable + s_GlobalMetadataHeader->typeDefinitionsCount)

void GcScanRootsInner(promote_func* fn, ScanContext* sc, uintptr_t bp, uintptr_t sp, std::vector<uintptr_t>& registers)
{
    if (sp > bp)
    {
        for (uintptr_t cur = sp; cur >= bp; INTPTR_DEC(cur))
        {
			PTR_PTR_Object pObj = (Object**)cur;
			PTR_Object addr = *pObj;
			if (IS_GC_HEAP_ADDR(addr))
			{
				Il2CppObject* obj = (Il2CppObject*)addr;
				void* klass = obj->klass;
				if (IS_VALID_KLASS(klass))
				{
					fn(pObj, sc, NULL);
				}
			}
        }
    }
    else
    {
        for (uintptr_t cur = sp; cur <= bp; INTPTR_INC(cur))
        {
			PTR_PTR_Object pObj = (Object**)cur;
			PTR_Object addr = *pObj;
			if (IS_GC_HEAP_ADDR(addr))
            {
				Il2CppObject* obj = (Il2CppObject*)addr;
				void* klass = obj->klass;
                if (IS_VALID_KLASS(klass))
                {
                    fn(pObj, sc, NULL);
                }
            }
        }
    }
    vector<uintptr_t>::iterator iter;
    for (iter = registers.begin(); iter != registers.end(); iter++)
    {
        PTR_Object addr = (PTR_Object)*iter;
		if (IS_GC_HEAP_ADDR(addr))
		{
			Il2CppObject* obj = (Il2CppObject*)addr;
			void* klass = obj->klass;
			if (IS_VALID_KLASS(klass))
			{

				//fn(pObj, sc, NULL);
			}
		}
    }
}

void GCToEEInterface::GcScanRoots(promote_func* fn,  int condemned, int max_gen, ScanContext* sc)
{
    // TODO: Implement - Scan stack roots on given thread
    uint64_t gcThreadId = 0;
    if (pCurrentThread)
    {
        il2cpp::os::Thread* th = pCurrentThread->GetNativeThread();
        if (th)
        {
            gcThreadId = th->Id();
        }
    }

    Thread* cur = ThreadStore::GetThreadList(NULL);
    std::vector<uintptr_t> registers;
    while (cur)
    {
        il2cpp::os::Thread* th = cur->GetNativeThread();
        if (th)
        {
            registers.clear();
			uintptr_t sp = clrgc::GetStackPointerAndRegisters(gcThreadId == th->Id(), th->GetNativeHandle(), registers);
            GcScanRootsInner(fn, sc, cur->GetBasePointer(), sp, registers);
        }
        cur = ThreadStore::GetThreadList(cur);
    }	
}

void GCToEEInterface::GcStartWork(int condemned, int max_gen)
{
}

void GCToEEInterface::AfterGcScanRoots(int condemned, int max_gen, ScanContext* sc)
{
}

void GCToEEInterface::GcBeforeBGCSweepWork()
{
}

void GCToEEInterface::GcDone(int condemned)
{
    
}

bool GCToEEInterface::RefCountedHandleCallbacks(Object * pObject)
{
    return false;
}

bool GCToEEInterface::IsPreemptiveGCDisabled(Thread * pThread)
{
    return pThread->PreemptiveGCDisabled();
}

void GCToEEInterface::EnablePreemptiveGC(Thread * pThread)
{
    return pThread->EnablePreemptiveGC();
}

void GCToEEInterface::DisablePreemptiveGC(Thread * pThread)
{
    pThread->DisablePreemptiveGC();
}

Thread* GCToEEInterface::GetThread()
{
    return ::GetThread();
}

bool GCToEEInterface::TrapReturningThreads()
{
    return !!g_TrapReturningThreads;
}

gc_alloc_context * GCToEEInterface::GetAllocContext(Thread * pThread)
{
    return pThread->GetAllocContext();
}

bool GCToEEInterface::CatchAtSafePoint(Thread * pThread)
{
    return pThread->CatchAtSafePoint();
}

void GCToEEInterface::GcEnumAllocContexts (enum_alloc_context_func* fn, void* param)
{
    Thread * pThread = NULL;
    while ((pThread = ThreadStore::GetThreadList(pThread)) != NULL)
    {
        fn(pThread->GetAllocContext(), param);
    }
}

void GCToEEInterface::SyncBlockCacheWeakPtrScan(HANDLESCANPROC scanProc, uintptr_t /*lp1*/, uintptr_t /*lp2*/)
{

}

void GCToEEInterface::SyncBlockCacheDemote(int /*max_gen*/)
{
}

void GCToEEInterface::SyncBlockCachePromotionsGranted(int /*max_gen*/)
{
}

void GCToEEInterface::DiagGCStart(int gen, bool isInduced)
{
}

void GCToEEInterface::DiagUpdateGenerationBounds()
{
}

void GCToEEInterface::DiagGCEnd(size_t index, int gen, int reason, bool fConcurrent)
{
}

void GCToEEInterface::DiagWalkFReachableObjects(void* gcContext)
{
}

void GCToEEInterface::DiagWalkSurvivors(void* gcContext)
{
}

void GCToEEInterface::DiagWalkLOHSurvivors(void* gcContext)
{
}

void GCToEEInterface::DiagWalkBGCSurvivors(void* gcContext)
{
}

void GCToEEInterface::StompWriteBarrier(WriteBarrierParameters* args)
{
}

void GCToEEInterface::EnableFinalization(bool foundFinalizers)
{
    // Signal to finalizer thread that there are objects to finalize
    // TODO: Implement for finalization
    //il2cpp::gc::GarbageCollector::NotifyFinalizers();
}

void GCToEEInterface::HandleFatalError(unsigned int exitCode)
{
    abort();
}

bool GCToEEInterface::ShouldFinalizeObjectForUnload(AppDomain* pDomain, Object* obj)
{
    return true;
}

bool GCToEEInterface::ForceFullGCToBeBlocking()
{
    return false;
}

bool GCToEEInterface::EagerFinalized(Object* obj)
{
    // The sample does not finalize anything eagerly.
    return false;
}

bool GCToEEInterface::GetBooleanConfigValue(const char* key, bool* value)
{
    return false;
}

bool GCToEEInterface::GetIntConfigValue(const char* key, int64_t* value)
{
    return false;
}

bool GCToEEInterface::GetStringConfigValue(const char* key, const char** value)
{
    return false;
}

void GCToEEInterface::FreeStringConfigValue(const char *value)
{

}

bool GCToEEInterface::IsGCThread()
{
    return false;
}

bool GCToEEInterface::WasCurrentThreadCreatedByGC()
{
    return false;
}

MethodTable* GCToEEInterface::GetFreeObjectMethodTable()
{
    return g_pFreeObjectMethodTable;
}

bool GCToEEInterface::CreateThread(void (*threadStart)(void*), void* arg, bool is_suspendable, const char* name)
{
    return false;
}

#include "private\gc_priv.h"
void GCToEEInterface::SuspendEE(SUSPEND_REASON reason)
{
    g_theGCHeap->SetGCInProgress(true);
    mutex.Lock();
    GC_stop_world_external();
}

void GCToEEInterface::RestartEE(bool bFinishedGC)
{
    GC_start_world_external();
    mutex.Unlock();

    g_theGCHeap->SetGCInProgress(false);
}
#endif