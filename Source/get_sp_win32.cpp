#if defined(GC_WIN32_THREADS)
#include "il2cpp-api.h"
#include <windows.h>
#include "private\gc_priv.h"
#include "clrgc.h"
namespace clrgc
{
	intptr_t GetStackPointerAndRegisters(bool isSelf, void* handle, std::vector<intptr_t>& registers)
	{
		intptr_t sp;
		if (isSelf)
		{
			sp = approx_sp();
		}
		else
		{
			/* Use saved sp value for blocked threads. */
			/* For unblocked threads call GetThreadContext().   */
			CONTEXT context;
			context.ContextFlags = CONTEXT_INTEGER | CONTEXT_CONTROL;

			IL2CPP_ASSERT(GetThreadContext((HANDLE)handle, &context));

			/* Push all registers that might point into the heap.  Frame        */
			/* pointer registers are included in case client code was           */
			/* compiled with the 'omit frame pointer' optimization.             */
#   define PUSH1(reg) registers.push_back((intptr_t)context.reg)
#   define PUSH2(r1,r2) (PUSH1(r1), PUSH1(r2))
#   define PUSH4(r1,r2,r3,r4) (PUSH2(r1,r2), PUSH2(r3,r4))
#   if defined(I386)
			PUSH4(Edi, Esi, Ebx, Edx), PUSH2(Ecx, Eax), PUSH1(Ebp);
			sp = (intptr_t)context.Esp;
#   elif defined(X86_64)
			PUSH4(Rax, Rcx, Rdx, Rbx); PUSH2(Rbp, Rsi); PUSH1(Rdi);
			PUSH4(R8, R9, R10, R11); PUSH4(R12, R13, R14, R15);
			sp = (intptr_t)context.Rsp;
#   elif defined(ARM32)
			PUSH4(R0, R1, R2, R3), PUSH4(R4, R5, R6, R7), PUSH4(R8, R9, R10, R11);
			PUSH1(R12);
			sp = (intptr_t)context.Sp;
#   elif defined(SHx)
			PUSH4(R0, R1, R2, R3), PUSH4(R4, R5, R6, R7), PUSH4(R8, R9, R10, R11);
			PUSH2(R12, R13), PUSH1(R14);
			sp = (intptr_t)context.R15;
#   elif defined(MIPS)
			PUSH4(IntAt, IntV0, IntV1, IntA0), PUSH4(IntA1, IntA2, IntA3, IntT0);
			PUSH4(IntT1, IntT2, IntT3, IntT4), PUSH4(IntT5, IntT6, IntT7, IntS0);
			PUSH4(IntS1, IntS2, IntS3, IntS4), PUSH4(IntS5, IntS6, IntS7, IntT8);
			PUSH4(IntT9, IntK0, IntK1, IntS8);
			sp = (intptr_t)context.IntSp;
#   elif defined(PPC)
			PUSH4(Gpr0, Gpr3, Gpr4, Gpr5), PUSH4(Gpr6, Gpr7, Gpr8, Gpr9);
			PUSH4(Gpr10, Gpr11, Gpr12, Gpr14), PUSH4(Gpr15, Gpr16, Gpr17, Gpr18);
			PUSH4(Gpr19, Gpr20, Gpr21, Gpr22), PUSH4(Gpr23, Gpr24, Gpr25, Gpr26);
			PUSH4(Gpr27, Gpr28, Gpr29, Gpr30), PUSH1(Gpr31);
			sp = (intptr_t)context.Gpr1;
#	elif defined(ALPHA)
			PUSH4(IntV0, IntT0, IntT1, IntT2), PUSH4(IntT3, IntT4, IntT5, IntT6);
			PUSH4(IntT7, IntS0, IntS1, IntS2), PUSH4(IntS3, IntS4, IntS5, IntFp);
			PUSH4(IntA0, IntA1, IntA2, IntA3), PUSH4(IntA4, IntA5, IntT8, IntT9);
			PUSH4(IntT10, IntT11, IntT12, IntAt);
			sp = (intptr_t)context.IntSp;
#   else
#     error "architecture is not supported"
#   endif
		}

		return sp;
	}
#endif
}