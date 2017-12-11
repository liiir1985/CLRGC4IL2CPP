#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// TestLib.TestClass2
struct TestClass2_t2823348084;
// System.String
struct String_t;
// TestLib.TestStruct
struct TestStruct_t1193123819;
struct TestStruct_t1193123819_marshaled_pinvoke;
struct TestStruct_t1193123819_marshaled_com;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_TestLib_TestStruct1193123819.h"
#include "AssemblyU2DCSharp_TestLib_TestClass22823348084.h"

// System.Byte TestLib.TestStruct::get_Byte()
extern "C"  uint8_t TestStruct_get_Byte_m2444952782 (TestStruct_t1193123819 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TestLib.TestStruct::set_Byte(System.Byte)
extern "C"  void TestStruct_set_Byte_m2328962547 (TestStruct_t1193123819 * __this, uint8_t ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 TestLib.TestStruct::get_Int()
extern "C"  int32_t TestStruct_get_Int_m468755181 (TestStruct_t1193123819 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TestLib.TestStruct::set_Int(System.Int32)
extern "C"  void TestStruct_set_Int_m2149398506 (TestStruct_t1193123819 * __this, int32_t ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// TestLib.TestClass2 TestLib.TestStruct::get_Object()
extern "C"  TestClass2_t2823348084 * TestStruct_get_Object_m1668251399 (TestStruct_t1193123819 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TestLib.TestStruct::set_Object(TestLib.TestClass2)
extern "C"  void TestStruct_set_Object_m3182382424 (TestStruct_t1193123819 * __this, TestClass2_t2823348084 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String TestLib.TestStruct::ToString()
extern "C"  String_t* TestStruct_ToString_m3534048920 (TestStruct_t1193123819 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;

// Methods for marshaling
struct TestStruct_t1193123819;
struct TestStruct_t1193123819_marshaled_pinvoke;

extern "C" void TestStruct_t1193123819_marshal_pinvoke(const TestStruct_t1193123819& unmarshaled, TestStruct_t1193123819_marshaled_pinvoke& marshaled);
extern "C" void TestStruct_t1193123819_marshal_pinvoke_back(const TestStruct_t1193123819_marshaled_pinvoke& marshaled, TestStruct_t1193123819& unmarshaled);
extern "C" void TestStruct_t1193123819_marshal_pinvoke_cleanup(TestStruct_t1193123819_marshaled_pinvoke& marshaled);

// Methods for marshaling
struct TestStruct_t1193123819;
struct TestStruct_t1193123819_marshaled_com;

extern "C" void TestStruct_t1193123819_marshal_com(const TestStruct_t1193123819& unmarshaled, TestStruct_t1193123819_marshaled_com& marshaled);
extern "C" void TestStruct_t1193123819_marshal_com_back(const TestStruct_t1193123819_marshaled_com& marshaled, TestStruct_t1193123819& unmarshaled);
extern "C" void TestStruct_t1193123819_marshal_com_cleanup(TestStruct_t1193123819_marshaled_com& marshaled);
