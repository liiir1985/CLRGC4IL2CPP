#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <limits>
#include <assert.h>

// TestLib.Main
struct Main_t3706940067;
// TestLib.TestClass
struct TestClass_t172611642;
// TestLib.TestClass2
struct TestClass2_t2823348084;

#include "class-internals.h"
#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Array3829468939.h"
#include "AssemblyU2DCSharp_U3CModuleU3E3783534214.h"
#include "AssemblyU2DCSharp_U3CModuleU3E3783534214MethodDeclarations.h"
#include "AssemblyU2DCSharp_TestLib_Main3706940067.h"
#include "AssemblyU2DCSharp_TestLib_Main3706940067MethodDeclarations.h"
#include "mscorlib_System_Void1841601450.h"
#include "mscorlib_System_Object2689449295MethodDeclarations.h"
#include "mscorlib_System_Collections_Generic_List_1_gen3836700070MethodDeclarations.h"
#include "mscorlib_System_Threading_ThreadStart3437517264MethodDeclarations.h"
#include "mscorlib_System_Threading_Thread241561612MethodDeclarations.h"
#include "mscorlib_System_Threading_Thread241561612.h"
#include "mscorlib_System_Collections_Generic_List_1_gen3836700070.h"
#include "mscorlib_System_Threading_ThreadStart3437517264.h"
#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_IntPtr2504060609.h"
#include "mscorlib_System_Int322071877448.h"
#include "AssemblyU2DCSharp_TestLib_TestClass172611642MethodDeclarations.h"
#include "AssemblyU2DCSharp_TestLib_TestClass22823348084MethodDeclarations.h"
#include "AssemblyU2DCSharp_TestLib_TestClass172611642.h"
#include "AssemblyU2DCSharp_TestLib_TestStruct1193123819.h"
#include "mscorlib_System_Byte3683104436.h"
#include "AssemblyU2DCSharp_TestLib_TestClass22823348084.h"
#include "AssemblyU2DCSharp_TestLib_TestStruct1193123819MethodDeclarations.h"
#include "mscorlib_System_Int64909078037.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void TestLib.Main::.ctor()
extern "C"  void Main__ctor_m1558680459 (Main_t3706940067 * __this, const MethodInfo* method)
{
	{
		Object__ctor_m2551263788(__this, /*hidden argument*/NULL);
		return;
	}
}
// System.Void TestLib.Main::TestGC()
extern Il2CppClass* List_1_t3836700070_il2cpp_TypeInfo_var;
extern Il2CppClass* Main_t3706940067_il2cpp_TypeInfo_var;
extern Il2CppClass* ThreadStart_t3437517264_il2cpp_TypeInfo_var;
extern Il2CppClass* Thread_t241561612_il2cpp_TypeInfo_var;
extern const MethodInfo* List_1__ctor_m574377014_MethodInfo_var;
extern const MethodInfo* Main_MainLoop_m709282870_MethodInfo_var;
extern const uint32_t Main_TestGC_m1651579141_MetadataUsageId;
extern "C"  void Main_TestGC_m1651579141 (Il2CppObject * __this /* static, unused */, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Main_TestGC_m1651579141_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	Thread_t241561612 * V_0 = NULL;
	{
		List_1_t3836700070 * L_0 = (List_1_t3836700070 *)il2cpp_codegen_object_new(List_1_t3836700070_il2cpp_TypeInfo_var);
		List_1__ctor_m574377014(L_0, /*hidden argument*/List_1__ctor_m574377014_MethodInfo_var);
		((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->set_lst_0(L_0);
		ThreadStart_t3437517264 * L_1 = ((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->get_U3CU3Ef__mgU24cache0_1();
		if (L_1)
		{
			goto IL_0023;
		}
	}
	{
		IntPtr_t L_2;
		L_2.set_m_value_0((void*)(void*)Main_MainLoop_m709282870_MethodInfo_var);
		ThreadStart_t3437517264 * L_3 = (ThreadStart_t3437517264 *)il2cpp_codegen_object_new(ThreadStart_t3437517264_il2cpp_TypeInfo_var);
		ThreadStart__ctor_m3015256841(L_3, NULL, L_2, /*hidden argument*/NULL);
		((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->set_U3CU3Ef__mgU24cache0_1(L_3);
	}

IL_0023:
	{
		ThreadStart_t3437517264 * L_4 = ((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->get_U3CU3Ef__mgU24cache0_1();
		Thread_t241561612 * L_5 = (Thread_t241561612 *)il2cpp_codegen_object_new(Thread_t241561612_il2cpp_TypeInfo_var);
		Thread__ctor_m4175494164(L_5, L_4, /*hidden argument*/NULL);
		V_0 = L_5;
		Thread_t241561612 * L_6 = V_0;
		NullCheck(L_6);
		Thread_Start_m1419497481(L_6, /*hidden argument*/NULL);
	}

IL_0034:
	{
		IL2CPP_RUNTIME_CLASS_INIT(Thread_t241561612_il2cpp_TypeInfo_var);
		Thread_Sleep_m1248422015(NULL /*static, unused*/, ((int32_t)100), /*hidden argument*/NULL);
		goto IL_0034;
	}
}
// System.Void TestLib.Main::MainLoop()
extern Il2CppClass* TestClass_t172611642_il2cpp_TypeInfo_var;
extern Il2CppClass* TestClass2_t2823348084_il2cpp_TypeInfo_var;
extern Il2CppClass* TestStruct_t1193123819_il2cpp_TypeInfo_var;
extern Il2CppClass* List_1_t3836700070_il2cpp_TypeInfo_var;
extern Il2CppClass* Main_t3706940067_il2cpp_TypeInfo_var;
extern Il2CppClass* Thread_t241561612_il2cpp_TypeInfo_var;
extern const MethodInfo* List_1__ctor_m574377014_MethodInfo_var;
extern const MethodInfo* List_1_Add_m823888578_MethodInfo_var;
extern const MethodInfo* List_1_get_Count_m3314063396_MethodInfo_var;
extern const MethodInfo* List_1_RemoveRange_m3027445787_MethodInfo_var;
extern const uint32_t Main_MainLoop_m709282870_MetadataUsageId;
extern "C"  void Main_MainLoop_m709282870 (Il2CppObject * __this /* static, unused */, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Main_MainLoop_m709282870_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	TestClass_t172611642 * V_0 = NULL;
	TestStruct_t1193123819  V_1;
	memset(&V_1, 0, sizeof(V_1));
	{
	}

IL_0001:
	{
		TestClass_t172611642 * L_0 = (TestClass_t172611642 *)il2cpp_codegen_object_new(TestClass_t172611642_il2cpp_TypeInfo_var);
		TestClass__ctor_m3958269440(L_0, /*hidden argument*/NULL);
		V_0 = L_0;
		TestClass_t172611642 * L_1 = V_0;
		NullCheck(L_1);
		TestClass_set_Byte_m3274944280(L_1, 1, /*hidden argument*/NULL);
		TestClass_t172611642 * L_2 = V_0;
		NullCheck(L_2);
		TestClass_set_Int_m3712982379(L_2, 2, /*hidden argument*/NULL);
		TestClass_t172611642 * L_3 = V_0;
		TestClass2_t2823348084 * L_4 = (TestClass2_t2823348084 *)il2cpp_codegen_object_new(TestClass2_t2823348084_il2cpp_TypeInfo_var);
		TestClass2__ctor_m3015933272(L_4, /*hidden argument*/NULL);
		NullCheck(L_3);
		TestClass_set_Object_m2601583493(L_3, L_4, /*hidden argument*/NULL);
		Initobj (TestStruct_t1193123819_il2cpp_TypeInfo_var, (&V_1));
		TestClass2_t2823348084 * L_5 = (TestClass2_t2823348084 *)il2cpp_codegen_object_new(TestClass2_t2823348084_il2cpp_TypeInfo_var);
		TestClass2__ctor_m3015933272(L_5, /*hidden argument*/NULL);
		TestStruct_set_Object_m3182382424((&V_1), L_5, /*hidden argument*/NULL);
		TestClass_t172611642 * L_6 = V_0;
		NullCheck(L_6);
		TestClass2_t2823348084 * L_7 = TestClass_get_Object_m4251471040(L_6, /*hidden argument*/NULL);
		TestStruct_t1193123819  L_8 = V_1;
		NullCheck(L_7);
		TestClass2_set_Struct_m2775423800(L_7, L_8, /*hidden argument*/NULL);
		List_1_t3836700070 * L_9 = (List_1_t3836700070 *)il2cpp_codegen_object_new(List_1_t3836700070_il2cpp_TypeInfo_var);
		List_1__ctor_m574377014(L_9, /*hidden argument*/List_1__ctor_m574377014_MethodInfo_var);
		((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->set_lst_0(L_9);
		List_1_t3836700070 * L_10 = ((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->get_lst_0();
		TestClass_t172611642 * L_11 = V_0;
		NullCheck(L_10);
		List_1_Add_m823888578(L_10, L_11, /*hidden argument*/List_1_Add_m823888578_MethodInfo_var);
		List_1_t3836700070 * L_12 = ((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->get_lst_0();
		NullCheck(L_12);
		int32_t L_13 = List_1_get_Count_m3314063396(L_12, /*hidden argument*/List_1_get_Count_m3314063396_MethodInfo_var);
		if ((((int32_t)L_13) <= ((int32_t)((int32_t)50000))))
		{
			goto IL_007f;
		}
	}
	{
		List_1_t3836700070 * L_14 = ((Main_t3706940067_StaticFields*)Main_t3706940067_il2cpp_TypeInfo_var->static_fields)->get_lst_0();
		NullCheck(L_14);
		List_1_RemoveRange_m3027445787(L_14, ((int32_t)10000), ((int32_t)40000), /*hidden argument*/List_1_RemoveRange_m3027445787_MethodInfo_var);
	}

IL_007f:
	{
		IL2CPP_RUNTIME_CLASS_INIT(Thread_t241561612_il2cpp_TypeInfo_var);
		Thread_Sleep_m1248422015(NULL /*static, unused*/, ((int32_t)100), /*hidden argument*/NULL);
		goto IL_0001;
	}
}
// System.Void TestLib.TestClass::.ctor()
extern "C"  void TestClass__ctor_m3958269440 (TestClass_t172611642 * __this, const MethodInfo* method)
{
	{
		Object__ctor_m2551263788(__this, /*hidden argument*/NULL);
		return;
	}
}
// System.Byte TestLib.TestClass::get_Byte()
extern "C"  uint8_t TestClass_get_Byte_m3362519125 (TestClass_t172611642 * __this, const MethodInfo* method)
{
	uint8_t V_0 = 0x0;
	{
		uint8_t L_0 = __this->get_U3CByteU3Ek__BackingField_0();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		uint8_t L_1 = V_0;
		return L_1;
	}
}
// System.Void TestLib.TestClass::set_Byte(System.Byte)
extern "C"  void TestClass_set_Byte_m3274944280 (TestClass_t172611642 * __this, uint8_t ___value0, const MethodInfo* method)
{
	{
		uint8_t L_0 = ___value0;
		__this->set_U3CByteU3Ek__BackingField_0(L_0);
		return;
	}
}
// System.Int32 TestLib.TestClass::get_Int()
extern "C"  int32_t TestClass_get_Int_m2189662148 (TestClass_t172611642 * __this, const MethodInfo* method)
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->get_U3CIntU3Ek__BackingField_1();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
// System.Void TestLib.TestClass::set_Int(System.Int32)
extern "C"  void TestClass_set_Int_m3712982379 (TestClass_t172611642 * __this, int32_t ___value0, const MethodInfo* method)
{
	{
		int32_t L_0 = ___value0;
		__this->set_U3CIntU3Ek__BackingField_1(L_0);
		return;
	}
}
// TestLib.TestClass2 TestLib.TestClass::get_Object()
extern "C"  TestClass2_t2823348084 * TestClass_get_Object_m4251471040 (TestClass_t172611642 * __this, const MethodInfo* method)
{
	TestClass2_t2823348084 * V_0 = NULL;
	{
		TestClass2_t2823348084 * L_0 = __this->get_U3CObjectU3Ek__BackingField_2();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		TestClass2_t2823348084 * L_1 = V_0;
		return L_1;
	}
}
// System.Void TestLib.TestClass::set_Object(TestLib.TestClass2)
extern "C"  void TestClass_set_Object_m2601583493 (TestClass_t172611642 * __this, TestClass2_t2823348084 * ___value0, const MethodInfo* method)
{
	{
		TestClass2_t2823348084 * L_0 = ___value0;
		__this->set_U3CObjectU3Ek__BackingField_2(L_0);
		return;
	}
}
// System.Void TestLib.TestClass2::.ctor()
extern "C"  void TestClass2__ctor_m3015933272 (TestClass2_t2823348084 * __this, const MethodInfo* method)
{
	{
		Object__ctor_m2551263788(__this, /*hidden argument*/NULL);
		return;
	}
}
// System.Int64 TestLib.TestClass2::get_Long()
extern "C"  int64_t TestClass2_get_Long_m2699894310 (TestClass2_t2823348084 * __this, const MethodInfo* method)
{
	int64_t V_0 = 0;
	{
		int64_t L_0 = __this->get_U3CLongU3Ek__BackingField_0();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		int64_t L_1 = V_0;
		return L_1;
	}
}
// System.Void TestLib.TestClass2::set_Long(System.Int64)
extern "C"  void TestClass2_set_Long_m3494713159 (TestClass2_t2823348084 * __this, int64_t ___value0, const MethodInfo* method)
{
	{
		int64_t L_0 = ___value0;
		__this->set_U3CLongU3Ek__BackingField_0(L_0);
		return;
	}
}
// TestLib.TestStruct TestLib.TestClass2::get_Struct()
extern "C"  TestStruct_t1193123819  TestClass2_get_Struct_m3273513589 (TestClass2_t2823348084 * __this, const MethodInfo* method)
{
	TestStruct_t1193123819  V_0;
	memset(&V_0, 0, sizeof(V_0));
	{
		TestStruct_t1193123819  L_0 = __this->get_U3CStructU3Ek__BackingField_1();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		TestStruct_t1193123819  L_1 = V_0;
		return L_1;
	}
}
// System.Void TestLib.TestClass2::set_Struct(TestLib.TestStruct)
extern "C"  void TestClass2_set_Struct_m2775423800 (TestClass2_t2823348084 * __this, TestStruct_t1193123819  ___value0, const MethodInfo* method)
{
	{
		TestStruct_t1193123819  L_0 = ___value0;
		__this->set_U3CStructU3Ek__BackingField_1(L_0);
		return;
	}
}
// System.Byte TestLib.TestStruct::get_Byte()
extern "C"  uint8_t TestStruct_get_Byte_m2444952782 (TestStruct_t1193123819 * __this, const MethodInfo* method)
{
	uint8_t V_0 = 0x0;
	{
		uint8_t L_0 = __this->get_U3CByteU3Ek__BackingField_0();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		uint8_t L_1 = V_0;
		return L_1;
	}
}
extern "C"  uint8_t TestStruct_get_Byte_m2444952782_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	TestStruct_t1193123819 * _thisAdjusted = reinterpret_cast<TestStruct_t1193123819 *>(__this + 1);
	return TestStruct_get_Byte_m2444952782(_thisAdjusted, method);
}
// System.Void TestLib.TestStruct::set_Byte(System.Byte)
extern "C"  void TestStruct_set_Byte_m2328962547 (TestStruct_t1193123819 * __this, uint8_t ___value0, const MethodInfo* method)
{
	{
		uint8_t L_0 = ___value0;
		__this->set_U3CByteU3Ek__BackingField_0(L_0);
		return;
	}
}
extern "C"  void TestStruct_set_Byte_m2328962547_AdjustorThunk (Il2CppObject * __this, uint8_t ___value0, const MethodInfo* method)
{
	TestStruct_t1193123819 * _thisAdjusted = reinterpret_cast<TestStruct_t1193123819 *>(__this + 1);
	TestStruct_set_Byte_m2328962547(_thisAdjusted, ___value0, method);
}
// System.Int32 TestLib.TestStruct::get_Int()
extern "C"  int32_t TestStruct_get_Int_m468755181 (TestStruct_t1193123819 * __this, const MethodInfo* method)
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->get_U3CIntU3Ek__BackingField_1();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
extern "C"  int32_t TestStruct_get_Int_m468755181_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	TestStruct_t1193123819 * _thisAdjusted = reinterpret_cast<TestStruct_t1193123819 *>(__this + 1);
	return TestStruct_get_Int_m468755181(_thisAdjusted, method);
}
// System.Void TestLib.TestStruct::set_Int(System.Int32)
extern "C"  void TestStruct_set_Int_m2149398506 (TestStruct_t1193123819 * __this, int32_t ___value0, const MethodInfo* method)
{
	{
		int32_t L_0 = ___value0;
		__this->set_U3CIntU3Ek__BackingField_1(L_0);
		return;
	}
}
extern "C"  void TestStruct_set_Int_m2149398506_AdjustorThunk (Il2CppObject * __this, int32_t ___value0, const MethodInfo* method)
{
	TestStruct_t1193123819 * _thisAdjusted = reinterpret_cast<TestStruct_t1193123819 *>(__this + 1);
	TestStruct_set_Int_m2149398506(_thisAdjusted, ___value0, method);
}
// TestLib.TestClass2 TestLib.TestStruct::get_Object()
extern "C"  TestClass2_t2823348084 * TestStruct_get_Object_m1668251399 (TestStruct_t1193123819 * __this, const MethodInfo* method)
{
	TestClass2_t2823348084 * V_0 = NULL;
	{
		TestClass2_t2823348084 * L_0 = __this->get_U3CObjectU3Ek__BackingField_2();
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		TestClass2_t2823348084 * L_1 = V_0;
		return L_1;
	}
}
extern "C"  TestClass2_t2823348084 * TestStruct_get_Object_m1668251399_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	TestStruct_t1193123819 * _thisAdjusted = reinterpret_cast<TestStruct_t1193123819 *>(__this + 1);
	return TestStruct_get_Object_m1668251399(_thisAdjusted, method);
}
// System.Void TestLib.TestStruct::set_Object(TestLib.TestClass2)
extern "C"  void TestStruct_set_Object_m3182382424 (TestStruct_t1193123819 * __this, TestClass2_t2823348084 * ___value0, const MethodInfo* method)
{
	{
		TestClass2_t2823348084 * L_0 = ___value0;
		__this->set_U3CObjectU3Ek__BackingField_2(L_0);
		return;
	}
}
extern "C"  void TestStruct_set_Object_m3182382424_AdjustorThunk (Il2CppObject * __this, TestClass2_t2823348084 * ___value0, const MethodInfo* method)
{
	TestStruct_t1193123819 * _thisAdjusted = reinterpret_cast<TestStruct_t1193123819 *>(__this + 1);
	TestStruct_set_Object_m3182382424(_thisAdjusted, ___value0, method);
}
// Conversion methods for marshalling of: TestLib.TestStruct
extern "C" void TestStruct_t1193123819_marshal_pinvoke(const TestStruct_t1193123819& unmarshaled, TestStruct_t1193123819_marshaled_pinvoke& marshaled)
{
	Il2CppCodeGenException* ___U3CObjectU3Ek__BackingField_2Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '<Object>k__BackingField' of type 'TestStruct': Reference type field marshaling is not supported.");
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CObjectU3Ek__BackingField_2Exception);
}
extern "C" void TestStruct_t1193123819_marshal_pinvoke_back(const TestStruct_t1193123819_marshaled_pinvoke& marshaled, TestStruct_t1193123819& unmarshaled)
{
	Il2CppCodeGenException* ___U3CObjectU3Ek__BackingField_2Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '<Object>k__BackingField' of type 'TestStruct': Reference type field marshaling is not supported.");
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CObjectU3Ek__BackingField_2Exception);
}
// Conversion method for clean up from marshalling of: TestLib.TestStruct
extern "C" void TestStruct_t1193123819_marshal_pinvoke_cleanup(TestStruct_t1193123819_marshaled_pinvoke& marshaled)
{
}
// Conversion methods for marshalling of: TestLib.TestStruct
extern "C" void TestStruct_t1193123819_marshal_com(const TestStruct_t1193123819& unmarshaled, TestStruct_t1193123819_marshaled_com& marshaled)
{
	Il2CppCodeGenException* ___U3CObjectU3Ek__BackingField_2Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '<Object>k__BackingField' of type 'TestStruct': Reference type field marshaling is not supported.");
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CObjectU3Ek__BackingField_2Exception);
}
extern "C" void TestStruct_t1193123819_marshal_com_back(const TestStruct_t1193123819_marshaled_com& marshaled, TestStruct_t1193123819& unmarshaled)
{
	Il2CppCodeGenException* ___U3CObjectU3Ek__BackingField_2Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '<Object>k__BackingField' of type 'TestStruct': Reference type field marshaling is not supported.");
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CObjectU3Ek__BackingField_2Exception);
}
// Conversion method for clean up from marshalling of: TestLib.TestStruct
extern "C" void TestStruct_t1193123819_marshal_com_cleanup(TestStruct_t1193123819_marshaled_com& marshaled)
{
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
