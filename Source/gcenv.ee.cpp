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
#include "os/Thread.h"
#include "os/Mutex.h"
#include "gc/GarbageCollector.h"


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

void ThreadStore::AttachCurrentThread()
{
    // TODO: Locks
    if (pCurrentThread)
        return;
    il2cpp::os::Thread* il2cppThread = il2cpp::os::Thread::GetOrCreateCurrentThread();

    Thread * pThread = new Thread();
    pThread->GetAllocContext()->init();
    pThread->SetIL2CPPThread(il2cppThread);
    pCurrentThread = pThread;

    mutex.Lock();	
    pThread->m_pNext = g_pThreadList;
    g_pThreadList = pThread;
    mutex.Unlock();
}

void GCToEEInterface::SuspendEE(SUSPEND_REASON reason)
{
    g_theGCHeap->SetGCInProgress(true);
    mutex.Lock();
    
    uint64_t gcThreadId = 0;
    if (pCurrentThread)
    {
        il2cpp::os::Thread* th = pCurrentThread->GetIL2CPPThread();
        if (th)
        {
            gcThreadId = th->Id();
        }
    }
    Thread* cur = ThreadStore::GetThreadList(NULL);
    while (cur)
    {
        il2cpp::os::Thread* th = cur->GetIL2CPPThread();
        if (th)
        {
            if (th->GetThreadState() == kThreadRuning && th->Id() != gcThreadId)
            {
                th->Suspend();
            }
        }
        cur = ThreadStore::GetThreadList(cur);
    }
}

void GCToEEInterface::RestartEE(bool bFinishedGC)
{
    // TODO: Implement
    uint64_t gcThreadId = 0;
    if (pCurrentThread)
    {
        il2cpp::os::Thread* th = pCurrentThread->GetIL2CPPThread();
        if (th)
        {
            gcThreadId = th->Id();
        }
    }
    Thread* cur = ThreadStore::GetThreadList(NULL);
    while (cur)
    {
        il2cpp::os::Thread* th = cur->GetIL2CPPThread();
        if (th)
        {
            if (th->GetThreadState() == kThreadRuning && th->Id() != gcThreadId)
            {
                th->Resume();
            }
        }
        cur = ThreadStore::GetThreadList(cur);
    }
    mutex.Unlock();

    g_theGCHeap->SetGCInProgress(false);
}

void GCToEEInterface::GcScanRoots(promote_func* fn,  int condemned, int max_gen, ScanContext* sc)
{
    // TODO: Implement - Scan stack roots on given thread
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
	il2cpp::gc::GarbageCollector::NotifyFinalizers();
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
#endif