#ifndef UNITY_PREFIX_H
#define UNITY_PREFIX_H

#include <assert.h>

#include <string>
#include <vector>
#include <set>
#include <map>

#ifdef _MSC_VER
// Visual Studio
    #include "Projects/PrecompiledHeaders/VisualStudioPrefix.h"
#elif defined(linux) || defined(__linux__)
    #include "Projects/PrecompiledHeaders/LinuxPrefix.h"
#elif defined(__APPLE__)
    #include "Projects/PrecompiledHeaders/OSXPrefix.h"
#else
// TODO
#endif


// These are needed for prefix configure
#define UNITY_EXTERNAL_TOOL 1
#define ENABLE_MULTITHREADED_CODE 1
#define SUPPORT_THREADS 1
// This has to be included before defining platform macros.
#include "Configuration/PrefixConfigure.h"

// These are now redundant because we are pulling in prefix configure
// and some of these should get stripped out
#ifdef _MSC_VER
#define UNITY_WIN 1
#define UNITY_OSX 0
#define UNITY_LINUX 0
#if _MSC_VER < 1800
#   define va_copy(a, z) ((void)((a)=(z)))
#endif
#elif __linux__ || linux
#define UNITY_WIN 0
#define UNITY_OSX 0
#define UNITY_LINUX 1
#else
#define UNITY_WIN 0
#define UNITY_OSX 1
#define UNITY_LINUX 0
#endif

#if defined(_AMD64_) || defined(__LP64__)
#define UNITY_32 0
#define UNITY_64 1
#else
#define UNITY_32 1
#define UNITY_64 0
#endif

#ifdef _DEBUG
#if defined(ENABLE_UNIT_TESTS)
#undef ENABLE_UNIT_TESTS
#endif
#define ENABLE_UNIT_TESTS 1
#endif

#if UNITY_WIN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define vsnprintf _vsnprintf
#define snprintf _snprintf
#pragma warning(disable:4244) // conversion from int|double to float, possible loss of data
typedef unsigned char UInt8;
typedef signed int SInt32;
typedef unsigned int UInt32;
typedef unsigned long long UInt64;
typedef unsigned short UInt16;
typedef signed long long SInt64;

// When UTF16 encoded path names are converted to UTF8, any Asian characters will expand to three bytes.
// Such paths cannot be passed to Windows API functions, they're purely for Unity's internal use.
#define MAX_PATH_UTF8 (MAX_PATH * 3)

#elif UNITY_OSX
#include <sys/syslimits.h>
#define MAX_PATH (PATH_MAX)
#define MAX_PATH_UTF8 (MAX_PATH * 3)
typedef signed long long SInt64;


#elif UNITY_LINUX
#include <limits.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>
typedef signed int SInt32;
typedef unsigned int UInt32;
typedef unsigned char UInt8;
typedef unsigned short UInt16;
typedef uint64_t  UInt64;           //  There are many places where we pass Uint64* to uint64*. The latter is defined as uint64_t and the former as long long.
typedef int64_t SInt64;
#else
typedef signed long long SInt64;
#endif


#include "Runtime/Allocator/MemoryMacros.h"
#include "Runtime/Utilities/Word.h"
#include "Configuration/UnityConfigure.h"
#include "Runtime/Logging/LogAssert.h"
#include "Runtime/Math/FloatConversion.h"

#include "Runtime/Utilities/vector_map.h"
#include "Runtime/Utilities/vector_set.h"
#include "Runtime/Utilities/Utility.h"


#endif
