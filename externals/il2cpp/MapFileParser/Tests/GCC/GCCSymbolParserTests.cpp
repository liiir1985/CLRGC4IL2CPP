#if ENABLE_UNIT_TESTS

#include <stdexcept>
#include <string>

#include "Runtime/Testing/Testing.h"
#include "../../GCC/GCCSymbolParser.h"

using namespace mapfileparser;

UNIT_TEST_SUITE(GCCSymbolParserTests)
{
    TEST(GCCSymbolParser_ThrowsAnExceptionOnEmptyInput)
    {
        CHECK_THROW(GCCSymbolParser::Parse("", ""), std::runtime_error);
    }

    static std::string firstLine = " .text.Array_InternalArray__ICollection_Contains_TisDTMXPathLinkedNode2_t868737712_m2716310233_gshared";
    static std::string secondLine = "                0x000000000039a1f8      0x2a8 /var/folders/tj/9rtndw3j6tdb0z3fqc21k3ph0000gp/T/il2cpp/AllTests_cpprunner_cache/objectfiles/8C79E9B8EDDA852A73F7465C089D46B3.o";

    TEST(GCCSymbolParser_FindsSymbolStart)
    {
        Symbol symbol = GCCSymbolParser::Parse(firstLine, secondLine);
        CHECK_EQUAL(0x0039a1f8, symbol.start);
    }

    TEST(GCCSymbolParser_FindsSymbolEnd)
    {
        Symbol symbol = GCCSymbolParser::Parse(firstLine, secondLine);
        CHECK_EQUAL(0x2a8, symbol.length);
    }

    TEST(GCCSymbolParser_SymbolName)
    {
        Symbol symbol = GCCSymbolParser::Parse(firstLine, secondLine);
        CHECK_EQUAL("Array_InternalArray__ICollection_Contains_TisDTMXPathLinkedNode2_t868737712_m2716310233_gshared", symbol.name);
    }

    TEST(GCCSymbolParser_SymbolObjectFile)
    {
        Symbol symbol = GCCSymbolParser::Parse(firstLine, secondLine);
        CHECK_EQUAL("/var/folders/tj/9rtndw3j6tdb0z3fqc21k3ph0000gp/T/il2cpp/AllTests_cpprunner_cache/objectfiles/8C79E9B8EDDA852A73F7465C089D46B3.o", symbol.objectFile);
    }

    TEST(GCCSymbolParser_NameOnFirstLine)
    {
        std::string specialFirstLine = " .text._Znwm    0x0000000001074d4c       0xcc /var/folders/tj/9rtndw3j6tdb0z3fqc21k3ph0000gp/T/il2cpp/AllTests_cpprunner_cache/objectfiles/71ED541AC8462284F486FD872FF4956C.o";
        std::string specialSecondLine = "operator new(unsigned long)";
        Symbol symbol = GCCSymbolParser::Parse(specialFirstLine, specialSecondLine);
        CHECK_EQUAL("_Znwm", symbol.name);
    }
}

#endif // ENABLE_UNIT_TESTS
