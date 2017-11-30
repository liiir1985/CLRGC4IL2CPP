#if ENABLE_UNIT_TESTS

#include <stdexcept>
#include "Runtime/Testing/Testing.h"
#include "../../Clang/ClangSectionParser.h"

using namespace mapfileparser;

UNIT_TEST_SUITE(ClangSectionParserTests)
{
    TEST(ClangSectionParser_ThrowsAnExceptionOnEmptyInput)
    {
        CHECK_THROW(ClangSectionParser::Parse(""), std::runtime_error);
    }

    TEST(ClangSectionParser_ParsesA32BitSection)
    {
        Section section = ClangSectionParser::Parse("0x00001F40\t0x00DDC22F\t__TEXT\t__text");
        CHECK_EQUAL(0x00001F40, section.start);
        CHECK_EQUAL(0x00DDC22F, section.length);
        CHECK_EQUAL("__text", section.name);
        CHECK_EQUAL("__TEXT", section.segmentName);
        CHECK_EQUAL(kSegmentTypeCode, section.segmentType);
    }

    TEST(ClangSectionParser_ParsesA64BitSection)
    {
        Section section = ClangSectionParser::Parse("0x1000072D0\t0x018B902C\t__TEXT\t__text");
        CHECK_EQUAL(0x1000072D0, section.start);
        CHECK_EQUAL(0x018B902C, section.length);
        CHECK_EQUAL("__text", section.name);
        CHECK_EQUAL("__TEXT", section.segmentName);
        CHECK_EQUAL(kSegmentTypeCode, section.segmentType);
    }

    TEST(ClangSectionParser_ParsesADataSegment)
    {
        Section section = ClangSectionParser::Parse("0x01059000\t0x00015ABC\t__DATA\t__nl_symbol_ptr");
        CHECK_EQUAL(0x01059000, section.start);
        CHECK_EQUAL(0x00015ABC, section.length);
        CHECK_EQUAL("__nl_symbol_ptr", section.name);
        CHECK_EQUAL("__DATA", section.segmentName);
        CHECK_EQUAL(kSegmentTypeData, section.segmentType);
    }
}

#endif // ENABLE_UNIT_TESTS
