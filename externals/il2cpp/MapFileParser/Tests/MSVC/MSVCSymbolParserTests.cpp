#if ENABLE_UNIT_TESTS

#include <stdexcept>
#include "Runtime/Testing/Testing.h"
#include "../../MSVC/MSVCSymbolParser.h"

using namespace mapfileparser;

UNIT_TEST_SUITE(MSVCSymbolParserTests)
{
    TEST(MSVCSymbolParser_ThrowsAnExceptionOnEmptyInput)
    {
        CHECK_THROW(MSVCSymbolParser::Parse(""), std::runtime_error);
    }

    TEST(MSVCSymbolParser_ParsesInternalSymbol)
    {
        Symbol symbol = MSVCSymbolParser::Parse(" 0000:00000000       __except_list              00000000     <absolute>", 0);
        CHECK_EQUAL(0x00000000, symbol.start);
        CHECK_EQUAL("__except_list", symbol.name);
        CHECK_EQUAL("<absolute>", symbol.objectFile);
    }

    TEST(MSVCSymbolParser_ParsesGeneratedCodeSymbol)
    {
        Symbol symbol = MSVCSymbolParser::Parse(" 0001:000000d0       _StreamingContext__ctor_m12119 004010d0 f   98F5E16DA77CA137853023FCE84040FD.obj", 0x400000);
        CHECK_EQUAL(0x000010d0, symbol.start);
        CHECK_EQUAL("_StreamingContext__ctor_m12119", symbol.name);
        CHECK_EQUAL("98F5E16DA77CA137853023FCE84040FD.obj", symbol.objectFile);
    }

    TEST(MSVCSymbolParser_Parses64BitSymbol)
    {
        Symbol symbol = MSVCSymbolParser::Parse(" 0001:00000000       ?copy@?$char_traits@D@std@@SAPEADPEADPEBD_K@Z 0000000140001000 f i 8976DE1CE997AE5147192D16F7988A94.obj", 0x0000000140000000);
        CHECK_EQUAL(0x0000000000001000, symbol.start);
        CHECK_EQUAL("?copy@?$char_traits@D@std@@SAPEADPEADPEBD_K@Z", symbol.name);
        CHECK_EQUAL("8976DE1CE997AE5147192D16F7988A94.obj", symbol.objectFile);
    }
}

#endif // ENABLE_UNIT_TESTS
