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

// System.Object
struct Il2CppObject;
// System.String
struct String_t;
// System.Predicate`1<System.Object>
struct Predicate_1_t1132419410;
// System.IAsyncResult
struct IAsyncResult_t1999651008;
// System.AsyncCallback
struct AsyncCallback_t163412349;
// System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>
struct Getter_2_t4179406139;
// System.Reflection.MonoProperty/StaticGetter`1<System.Object>
struct StaticGetter_1_t1095697167;

#include "class-internals.h"
#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Array3829468939.h"
#include "mscorlib_System_Nullable_1_gen1693325264.h"
#include "mscorlib_System_Nullable_1_gen1693325264MethodDeclarations.h"
#include "mscorlib_System_TimeSpan3430258949.h"
#include "mscorlib_System_Void1841601450.h"
#include "mscorlib_System_Boolean3825574718.h"
#include "mscorlib_System_InvalidOperationException721527559MethodDeclarations.h"
#include "mscorlib_System_String2029220233.h"
#include "mscorlib_System_InvalidOperationException721527559.h"
#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_TimeSpan3430258949MethodDeclarations.h"
#include "mscorlib_System_ValueType3507792607MethodDeclarations.h"
#include "mscorlib_System_ValueType3507792607.h"
#include "mscorlib_System_Int322071877448.h"
#include "mscorlib_System_String2029220233MethodDeclarations.h"
#include "mscorlib_System_Predicate_1_gen1132419410.h"
#include "mscorlib_System_Predicate_1_gen1132419410MethodDeclarations.h"
#include "mscorlib_System_IntPtr2504060609.h"
#include "mscorlib_System_AsyncCallback163412349.h"
#include "mscorlib_System_Reflection_MonoProperty_Getter_2_g4179406139.h"
#include "mscorlib_System_Reflection_MonoProperty_Getter_2_g4179406139MethodDeclarations.h"
#include "mscorlib_System_Reflection_MonoProperty_StaticGett1095697167.h"
#include "mscorlib_System_Reflection_MonoProperty_StaticGett1095697167MethodDeclarations.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void System.Nullable`1<System.TimeSpan>::.ctor(T)
extern "C"  void Nullable_1__ctor_m796575255_gshared (Nullable_1_t1693325264 * __this, TimeSpan_t3430258949  ___value0, const MethodInfo* method)
{
	{
		__this->set_has_value_1((bool)1);
		TimeSpan_t3430258949  L_0 = ___value0;
		__this->set_value_0(L_0);
		return;
	}
}
extern "C"  void Nullable_1__ctor_m796575255_AdjustorThunk (Il2CppObject * __this, TimeSpan_t3430258949  ___value0, const MethodInfo* method)
{
	Nullable_1_t1693325264  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	Nullable_1__ctor_m796575255(&_thisAdjusted, ___value0, method);
	*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1) = _thisAdjusted.get_value_0();
}
// System.Boolean System.Nullable`1<System.TimeSpan>::get_HasValue()
extern "C"  bool Nullable_1_get_HasValue_m3663286555_gshared (Nullable_1_t1693325264 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		return L_0;
	}
}
extern "C"  bool Nullable_1_get_HasValue_m3663286555_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1693325264  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_get_HasValue_m3663286555(&_thisAdjusted, method);
	*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// T System.Nullable`1<System.TimeSpan>::get_Value()
extern Il2CppClass* InvalidOperationException_t721527559_il2cpp_TypeInfo_var;
extern Il2CppCodeGenString* _stringLiteral2004437333;
extern const uint32_t Nullable_1_get_Value_m1743067844_MetadataUsageId;
extern "C"  TimeSpan_t3430258949  Nullable_1_get_Value_m1743067844_gshared (Nullable_1_t1693325264 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_get_Value_m1743067844_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		InvalidOperationException_t721527559 * L_1 = (InvalidOperationException_t721527559 *)il2cpp_codegen_object_new(InvalidOperationException_t721527559_il2cpp_TypeInfo_var);
		InvalidOperationException__ctor_m2801133788(L_1, (String_t*)_stringLiteral2004437333, /*hidden argument*/NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1);
	}

IL_0016:
	{
		TimeSpan_t3430258949  L_2 = (TimeSpan_t3430258949 )__this->get_value_0();
		return L_2;
	}
}
extern "C"  TimeSpan_t3430258949  Nullable_1_get_Value_m1743067844_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1693325264  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	TimeSpan_t3430258949  _returnValue = Nullable_1_get_Value_m1743067844(&_thisAdjusted, method);
	*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<System.TimeSpan>::Equals(System.Object)
extern "C"  bool Nullable_1_Equals_m3860982732_gshared (Nullable_1_t1693325264 * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = ___other0;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		bool L_1 = (bool)__this->get_has_value_1();
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}

IL_0010:
	{
		Il2CppObject * L_2 = ___other0;
		if (((Il2CppObject *)IsInst(L_2, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0))))
		{
			goto IL_001d;
		}
	}
	{
		return (bool)0;
	}

IL_001d:
	{
		Il2CppObject * L_3 = ___other0;
		void* L_4 = alloca(sizeof(Nullable_1_t1693325264 ));
		UnBoxNullable(L_3, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0), L_4);
		bool L_5 = Nullable_1_Equals_m1889119397((Nullable_1_t1693325264 *)__this, (Nullable_1_t1693325264 )((*(Nullable_1_t1693325264 *)((Nullable_1_t1693325264 *)L_4))), /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(InitializedTypeInfo(method->declaring_type)->rgctx_data, 1));
		return L_5;
	}
}
extern "C"  bool Nullable_1_Equals_m3860982732_AdjustorThunk (Il2CppObject * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	Nullable_1_t1693325264  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m3860982732(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<System.TimeSpan>::Equals(System.Nullable`1<T>)
extern "C"  bool Nullable_1_Equals_m1889119397_gshared (Nullable_1_t1693325264 * __this, Nullable_1_t1693325264  ___other0, const MethodInfo* method)
{
	{
		bool L_0 = (bool)(&___other0)->get_has_value_1();
		bool L_1 = (bool)__this->get_has_value_1();
		if ((((int32_t)L_0) == ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)0;
	}

IL_0014:
	{
		bool L_2 = (bool)__this->get_has_value_1();
		if (L_2)
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}

IL_0021:
	{
		TimeSpan_t3430258949 * L_3 = (TimeSpan_t3430258949 *)(&___other0)->get_address_of_value_0();
		TimeSpan_t3430258949  L_4 = (TimeSpan_t3430258949 )__this->get_value_0();
		TimeSpan_t3430258949  L_5 = L_4;
		Il2CppObject * L_6 = Box(IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 2), &L_5);
		bool L_7 = TimeSpan_Equals_m4102942751((TimeSpan_t3430258949 *)L_3, (Il2CppObject *)L_6, /*hidden argument*/NULL);
		return L_7;
	}
}
extern "C"  bool Nullable_1_Equals_m1889119397_AdjustorThunk (Il2CppObject * __this, Nullable_1_t1693325264  ___other0, const MethodInfo* method)
{
	Nullable_1_t1693325264  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m1889119397(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Int32 System.Nullable`1<System.TimeSpan>::GetHashCode()
extern "C"  int32_t Nullable_1_GetHashCode_m1791015856_gshared (Nullable_1_t1693325264 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_000d;
		}
	}
	{
		return 0;
	}

IL_000d:
	{
		TimeSpan_t3430258949 * L_1 = (TimeSpan_t3430258949 *)__this->get_address_of_value_0();
		int32_t L_2 = TimeSpan_GetHashCode_m550404245((TimeSpan_t3430258949 *)L_1, /*hidden argument*/NULL);
		return L_2;
	}
}
extern "C"  int32_t Nullable_1_GetHashCode_m1791015856_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1693325264  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	int32_t _returnValue = Nullable_1_GetHashCode_m1791015856(&_thisAdjusted, method);
	*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.String System.Nullable`1<System.TimeSpan>::ToString()
extern Il2CppClass* String_t_il2cpp_TypeInfo_var;
extern const uint32_t Nullable_1_ToString_m1238126148_MetadataUsageId;
extern "C"  String_t* Nullable_1_ToString_m1238126148_gshared (Nullable_1_t1693325264 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_ToString_m1238126148_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (!L_0)
		{
			goto IL_001d;
		}
	}
	{
		TimeSpan_t3430258949 * L_1 = (TimeSpan_t3430258949 *)__this->get_address_of_value_0();
		String_t* L_2 = TimeSpan_ToString_m2947282901((TimeSpan_t3430258949 *)L_1, /*hidden argument*/NULL);
		return L_2;
	}

IL_001d:
	{
		IL2CPP_RUNTIME_CLASS_INIT(String_t_il2cpp_TypeInfo_var);
		String_t* L_3 = ((String_t_StaticFields*)String_t_il2cpp_TypeInfo_var->static_fields)->get_Empty_2();
		return L_3;
	}
}
extern "C"  String_t* Nullable_1_ToString_m1238126148_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1693325264  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	String_t* _returnValue = Nullable_1_ToString_m1238126148(&_thisAdjusted, method);
	*reinterpret_cast<TimeSpan_t3430258949 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Void System.Predicate`1<System.Object>::.ctor(System.Object,System.IntPtr)
extern "C"  void Predicate_1__ctor_m2289454599_gshared (Predicate_1_t1132419410 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method)
{
	__this->set_method_ptr_0((Il2CppMethodPointer)((MethodInfo*)___method1.get_m_value_0())->methodPointer);
	__this->set_method_3(___method1);
	__this->set_m_target_2(___object0);
}
// System.Boolean System.Predicate`1<System.Object>::Invoke(T)
extern "C"  bool Predicate_1_Invoke_m4047721271_gshared (Predicate_1_t1132419410 * __this, Il2CppObject * ___obj0, const MethodInfo* method)
{
	if(__this->get_prev_9() != NULL)
	{
		Predicate_1_Invoke_m4047721271((Predicate_1_t1132419410 *)__this->get_prev_9(),___obj0, method);
	}
	il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	bool ___methodIsStatic = MethodIsStatic((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	if (__this->get_m_target_2() != NULL && ___methodIsStatic)
	{
		typedef bool (*FunctionPointerType) (Il2CppObject *, void* __this, Il2CppObject * ___obj0, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(NULL,__this->get_m_target_2(),___obj0,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else if (__this->get_m_target_2() != NULL || ___methodIsStatic)
	{
		typedef bool (*FunctionPointerType) (void* __this, Il2CppObject * ___obj0, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(__this->get_m_target_2(),___obj0,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else
	{
		typedef bool (*FunctionPointerType) (void* __this, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(___obj0,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
}
// System.IAsyncResult System.Predicate`1<System.Object>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * Predicate_1_BeginInvoke_m3556950370_gshared (Predicate_1_t1132419410 * __this, Il2CppObject * ___obj0, AsyncCallback_t163412349 * ___callback1, Il2CppObject * ___object2, const MethodInfo* method)
{
	void *__d_args[2] = {0};
	__d_args[0] = ___obj0;
	return (Il2CppObject *)il2cpp_codegen_delegate_begin_invoke((Il2CppDelegate*)__this, __d_args, (Il2CppDelegate*)___callback1, (Il2CppObject*)___object2);
}
// System.Boolean System.Predicate`1<System.Object>::EndInvoke(System.IAsyncResult)
extern "C"  bool Predicate_1_EndInvoke_m3656575065_gshared (Predicate_1_t1132419410 * __this, Il2CppObject * ___result0, const MethodInfo* method)
{
	Il2CppObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
	return *(bool*)UnBox ((Il2CppCodeGenObject*)__result);
}
// System.Void System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::.ctor(System.Object,System.IntPtr)
extern "C"  void Getter_2__ctor_m653998582_gshared (Getter_2_t4179406139 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method)
{
	__this->set_method_ptr_0((Il2CppMethodPointer)((MethodInfo*)___method1.get_m_value_0())->methodPointer);
	__this->set_method_3(___method1);
	__this->set_m_target_2(___object0);
}
// R System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::Invoke(T)
extern "C"  Il2CppObject * Getter_2_Invoke_m3338489829_gshared (Getter_2_t4179406139 * __this, Il2CppObject * ____this0, const MethodInfo* method)
{
	if(__this->get_prev_9() != NULL)
	{
		Getter_2_Invoke_m3338489829((Getter_2_t4179406139 *)__this->get_prev_9(),____this0, method);
	}
	il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	bool ___methodIsStatic = MethodIsStatic((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	if (__this->get_m_target_2() != NULL && ___methodIsStatic)
	{
		typedef Il2CppObject * (*FunctionPointerType) (Il2CppObject *, void* __this, Il2CppObject * ____this0, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(NULL,__this->get_m_target_2(),____this0,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else if (__this->get_m_target_2() != NULL || ___methodIsStatic)
	{
		typedef Il2CppObject * (*FunctionPointerType) (void* __this, Il2CppObject * ____this0, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(__this->get_m_target_2(),____this0,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else
	{
		typedef Il2CppObject * (*FunctionPointerType) (void* __this, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(____this0,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
}
// System.IAsyncResult System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * Getter_2_BeginInvoke_m2080015031_gshared (Getter_2_t4179406139 * __this, Il2CppObject * ____this0, AsyncCallback_t163412349 * ___callback1, Il2CppObject * ___object2, const MethodInfo* method)
{
	void *__d_args[2] = {0};
	__d_args[0] = ____this0;
	return (Il2CppObject *)il2cpp_codegen_delegate_begin_invoke((Il2CppDelegate*)__this, __d_args, (Il2CppDelegate*)___callback1, (Il2CppObject*)___object2);
}
// R System.Reflection.MonoProperty/Getter`2<System.Object,System.Object>::EndInvoke(System.IAsyncResult)
extern "C"  Il2CppObject * Getter_2_EndInvoke_m977999903_gshared (Getter_2_t4179406139 * __this, Il2CppObject * ___result0, const MethodInfo* method)
{
	Il2CppObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
	return (Il2CppObject *)__result;
}
// System.Void System.Reflection.MonoProperty/StaticGetter`1<System.Object>::.ctor(System.Object,System.IntPtr)
extern "C"  void StaticGetter_1__ctor_m1290492285_gshared (StaticGetter_1_t1095697167 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method)
{
	__this->set_method_ptr_0((Il2CppMethodPointer)((MethodInfo*)___method1.get_m_value_0())->methodPointer);
	__this->set_method_3(___method1);
	__this->set_m_target_2(___object0);
}
// R System.Reflection.MonoProperty/StaticGetter`1<System.Object>::Invoke()
extern "C"  Il2CppObject * StaticGetter_1_Invoke_m1348877692_gshared (StaticGetter_1_t1095697167 * __this, const MethodInfo* method)
{
	if(__this->get_prev_9() != NULL)
	{
		StaticGetter_1_Invoke_m1348877692((StaticGetter_1_t1095697167 *)__this->get_prev_9(), method);
	}
	il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	bool ___methodIsStatic = MethodIsStatic((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	if ((__this->get_m_target_2() != NULL || MethodHasParameters((MethodInfo*)(__this->get_method_3().get_m_value_0()))) && ___methodIsStatic)
	{
		typedef Il2CppObject * (*FunctionPointerType) (Il2CppObject *, void* __this, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(NULL,__this->get_m_target_2(),(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else
	{
		typedef Il2CppObject * (*FunctionPointerType) (void* __this, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(__this->get_m_target_2(),(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
}
// System.IAsyncResult System.Reflection.MonoProperty/StaticGetter`1<System.Object>::BeginInvoke(System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * StaticGetter_1_BeginInvoke_m2732579814_gshared (StaticGetter_1_t1095697167 * __this, AsyncCallback_t163412349 * ___callback0, Il2CppObject * ___object1, const MethodInfo* method)
{
	void *__d_args[1] = {0};
	return (Il2CppObject *)il2cpp_codegen_delegate_begin_invoke((Il2CppDelegate*)__this, __d_args, (Il2CppDelegate*)___callback0, (Il2CppObject*)___object1);
}
// R System.Reflection.MonoProperty/StaticGetter`1<System.Object>::EndInvoke(System.IAsyncResult)
extern "C"  Il2CppObject * StaticGetter_1_EndInvoke_m44757160_gshared (StaticGetter_1_t1095697167 * __this, Il2CppObject * ___result0, const MethodInfo* method)
{
	Il2CppObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
	return (Il2CppObject *)__result;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
