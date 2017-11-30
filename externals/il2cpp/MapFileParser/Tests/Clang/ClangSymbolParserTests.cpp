#if ENABLE_UNIT_TESTS

#include <stdexcept>
#include "Runtime/Testing/Testing.h"
#include "../../Clang/ClangSymbolParser.h"

using namespace mapfileparser;

UNIT_TEST_SUITE(ClangSymbolParserTests)
{
    TEST(ClangSymbolParser_ThrowsAnExceptionOnEmptyInput)
    {
        CHECK_THROW(ClangSymbolParser::Parse(""), std::runtime_error);
    }

    TEST(ClangSymbolParser_ParsersA32BitSymbol)
    {
        ClangSymbol clangSymbol = ClangSymbolParser::Parse(" 0x00001F40\t0x000000D0\t[  3] _U3CRegisterObjectU3Ec__AnonStorey2__ctor_m12113");
        CHECK_EQUAL(0x00001F40, clangSymbol.symbol.start);
        CHECK_EQUAL(0x000000D0, clangSymbol.symbol.length);
        CHECK_EQUAL("_U3CRegisterObjectU3Ec__AnonStorey2__ctor_m12113", clangSymbol.symbol.name);
        CHECK_EQUAL(3, clangSymbol.objectFileIndex);
    }

    TEST(ClangSymbolParser_ParsersA64BitSymbol)
    {
        ClangSymbol clangSymbol = ClangSymbolParser::Parse(" 0x100EC9264\t0x0000004C\t[709] __ZNK5Umbra11TomeContext10getGateMapEPKv");
        CHECK_EQUAL(0x100EC9264, clangSymbol.symbol.start);
        CHECK_EQUAL(0x0000004C, clangSymbol.symbol.length);
        CHECK_EQUAL("__ZNK5Umbra11TomeContext10getGateMapEPKv", clangSymbol.symbol.name);
        CHECK_EQUAL(709, clangSymbol.objectFileIndex);
    }
}

#endif // ENABLE_UNIT_TESTS
