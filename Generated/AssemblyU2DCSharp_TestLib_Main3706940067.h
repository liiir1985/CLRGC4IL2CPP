#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.List`1<TestLib.TestClass>
struct List_1_t3836700070;
// System.Threading.ThreadStart
struct ThreadStart_t3437517264;

#include "mscorlib_System_Object2689449295.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// TestLib.Main
struct  Main_t3706940067  : public Il2CppObject
{
public:

public:
};

struct Main_t3706940067_StaticFields
{
public:
	// System.Collections.Generic.List`1<TestLib.TestClass> TestLib.Main::lst
	List_1_t3836700070 * ___lst_0;
	// System.Threading.ThreadStart TestLib.Main::<>f__mg$cache0
	ThreadStart_t3437517264 * ___U3CU3Ef__mgU24cache0_1;

public:
	inline static int32_t get_offset_of_lst_0() { return static_cast<int32_t>(offsetof(Main_t3706940067_StaticFields, ___lst_0)); }
	inline List_1_t3836700070 * get_lst_0() const { return ___lst_0; }
	inline List_1_t3836700070 ** get_address_of_lst_0() { return &___lst_0; }
	inline void set_lst_0(List_1_t3836700070 * value)
	{
		___lst_0 = value;
		Il2CppCodeGenWriteBarrier(&___lst_0, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache0_1() { return static_cast<int32_t>(offsetof(Main_t3706940067_StaticFields, ___U3CU3Ef__mgU24cache0_1)); }
	inline ThreadStart_t3437517264 * get_U3CU3Ef__mgU24cache0_1() const { return ___U3CU3Ef__mgU24cache0_1; }
	inline ThreadStart_t3437517264 ** get_address_of_U3CU3Ef__mgU24cache0_1() { return &___U3CU3Ef__mgU24cache0_1; }
	inline void set_U3CU3Ef__mgU24cache0_1(ThreadStart_t3437517264 * value)
	{
		___U3CU3Ef__mgU24cache0_1 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache0_1, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
