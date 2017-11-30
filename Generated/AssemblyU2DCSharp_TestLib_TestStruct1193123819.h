#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// TestLib.TestClass2
struct TestClass2_t2823348084;

#include "mscorlib_System_ValueType3507792607.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// TestLib.TestStruct
struct  TestStruct_t1193123819 
{
public:
	union
	{
		struct
		{
			// System.Byte TestLib.TestStruct::<Byte>k__BackingField
			uint8_t ___U3CByteU3Ek__BackingField_0;
			// System.Int32 TestLib.TestStruct::<Int>k__BackingField
			int32_t ___U3CIntU3Ek__BackingField_1;
			// TestLib.TestClass2 TestLib.TestStruct::<Object>k__BackingField
			TestClass2_t2823348084 * ___U3CObjectU3Ek__BackingField_2;
		};
		uint8_t TestStruct_t1193123819__padding[1];
	};

public:
	inline static int32_t get_offset_of_U3CByteU3Ek__BackingField_0() { return static_cast<int32_t>(offsetof(TestStruct_t1193123819, ___U3CByteU3Ek__BackingField_0)); }
	inline uint8_t get_U3CByteU3Ek__BackingField_0() const { return ___U3CByteU3Ek__BackingField_0; }
	inline uint8_t* get_address_of_U3CByteU3Ek__BackingField_0() { return &___U3CByteU3Ek__BackingField_0; }
	inline void set_U3CByteU3Ek__BackingField_0(uint8_t value)
	{
		___U3CByteU3Ek__BackingField_0 = value;
	}

	inline static int32_t get_offset_of_U3CIntU3Ek__BackingField_1() { return static_cast<int32_t>(offsetof(TestStruct_t1193123819, ___U3CIntU3Ek__BackingField_1)); }
	inline int32_t get_U3CIntU3Ek__BackingField_1() const { return ___U3CIntU3Ek__BackingField_1; }
	inline int32_t* get_address_of_U3CIntU3Ek__BackingField_1() { return &___U3CIntU3Ek__BackingField_1; }
	inline void set_U3CIntU3Ek__BackingField_1(int32_t value)
	{
		___U3CIntU3Ek__BackingField_1 = value;
	}

	inline static int32_t get_offset_of_U3CObjectU3Ek__BackingField_2() { return static_cast<int32_t>(offsetof(TestStruct_t1193123819, ___U3CObjectU3Ek__BackingField_2)); }
	inline TestClass2_t2823348084 * get_U3CObjectU3Ek__BackingField_2() const { return ___U3CObjectU3Ek__BackingField_2; }
	inline TestClass2_t2823348084 ** get_address_of_U3CObjectU3Ek__BackingField_2() { return &___U3CObjectU3Ek__BackingField_2; }
	inline void set_U3CObjectU3Ek__BackingField_2(TestClass2_t2823348084 * value)
	{
		___U3CObjectU3Ek__BackingField_2 = value;
		Il2CppCodeGenWriteBarrier(&___U3CObjectU3Ek__BackingField_2, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of TestLib.TestStruct
struct TestStruct_t1193123819_marshaled_pinvoke
{
	union
	{
		struct
		{
			uint8_t ___U3CByteU3Ek__BackingField_0;
			int32_t ___U3CIntU3Ek__BackingField_1;
			TestClass2_t2823348084 * ___U3CObjectU3Ek__BackingField_2;
		};
		uint8_t TestStruct_t1193123819__padding[1];
	};
};
// Native definition for COM marshalling of TestLib.TestStruct
struct TestStruct_t1193123819_marshaled_com
{
	union
	{
		struct
		{
			uint8_t ___U3CByteU3Ek__BackingField_0;
			int32_t ___U3CIntU3Ek__BackingField_1;
			TestClass2_t2823348084 * ___U3CObjectU3Ek__BackingField_2;
		};
		uint8_t TestStruct_t1193123819__padding[1];
	};
};
