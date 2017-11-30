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

// System.Globalization.RegionInfo
struct RegionInfo_t3784626978;
// System.String
struct String_t;
// System.Globalization.CultureInfo
struct CultureInfo_t3500843524;
// System.Object
struct Il2CppObject;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_String2029220233.h"
#include "mscorlib_System_Globalization_CultureInfo3500843524.h"
#include "mscorlib_System_Object2689449295.h"

// System.Void System.Globalization.RegionInfo::.ctor(System.Int32)
extern "C"  void RegionInfo__ctor_m2058831971 (RegionInfo_t3784626978 * __this, int32_t ___culture0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Globalization.RegionInfo::.ctor(System.String)
extern "C"  void RegionInfo__ctor_m997788172 (RegionInfo_t3784626978 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Globalization.RegionInfo System.Globalization.RegionInfo::get_CurrentRegion()
extern "C"  RegionInfo_t3784626978 * RegionInfo_get_CurrentRegion_m4024176963 (Il2CppObject * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.RegionInfo::GetByTerritory(System.Globalization.CultureInfo)
extern "C"  bool RegionInfo_GetByTerritory_m3452395101 (RegionInfo_t3784626978 * __this, CultureInfo_t3500843524 * ___ci0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.RegionInfo::construct_internal_region_from_name(System.String)
extern "C"  bool RegionInfo_construct_internal_region_from_name_m3316088619 (RegionInfo_t3784626978 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_CurrencyEnglishName()
extern "C"  String_t* RegionInfo_get_CurrencyEnglishName_m2213279750 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_CurrencySymbol()
extern "C"  String_t* RegionInfo_get_CurrencySymbol_m1179400943 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_DisplayName()
extern "C"  String_t* RegionInfo_get_DisplayName_m549004047 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_EnglishName()
extern "C"  String_t* RegionInfo_get_EnglishName_m159404747 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Globalization.RegionInfo::get_GeoId()
extern "C"  int32_t RegionInfo_get_GeoId_m3780064049 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.RegionInfo::get_IsMetric()
extern "C"  bool RegionInfo_get_IsMetric_m3995025969 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_ISOCurrencySymbol()
extern "C"  String_t* RegionInfo_get_ISOCurrencySymbol_m2832857310 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_NativeName()
extern "C"  String_t* RegionInfo_get_NativeName_m3252496470 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_CurrencyNativeName()
extern "C"  String_t* RegionInfo_get_CurrencyNativeName_m4045782543 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_Name()
extern "C"  String_t* RegionInfo_get_Name_m3906500881 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_ThreeLetterISORegionName()
extern "C"  String_t* RegionInfo_get_ThreeLetterISORegionName_m3528516148 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_ThreeLetterWindowsRegionName()
extern "C"  String_t* RegionInfo_get_ThreeLetterWindowsRegionName_m2372038184 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::get_TwoLetterISORegionName()
extern "C"  String_t* RegionInfo_get_TwoLetterISORegionName_m3785663754 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean System.Globalization.RegionInfo::Equals(System.Object)
extern "C"  bool RegionInfo_Equals_m800719235 (RegionInfo_t3784626978 * __this, Il2CppObject * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 System.Globalization.RegionInfo::GetHashCode()
extern "C"  int32_t RegionInfo_GetHashCode_m1038358761 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String System.Globalization.RegionInfo::ToString()
extern "C"  String_t* RegionInfo_ToString_m876145401 (RegionInfo_t3784626978 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
