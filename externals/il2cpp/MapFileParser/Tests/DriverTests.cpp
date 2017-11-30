#if ENABLE_UNIT_TESTS

#include <sstream>
#include <string>
#include "Runtime/Testing/Testing.h"
#include "../Driver.h"

using namespace mapfileparser;

UNIT_TEST_SUITE(DriverTests)
{
    TEST(DriverReturnsCorrectValueWithIncorrectNumberOfArguments)
    {
        std::stringstream unused;
        CHECK_EQUAL(1, Driver::Run(1, NULL, unused));
    }

    TEST(DriverOutputsCorrectErrorWithIncorrectNumberOfArguments)
    {
        std::stringstream output;
        Driver::Run(1, NULL, output);
        CHECK_EQUAL("Usage: MapFileParser -format=<MSVC|Clang|SNC|GCC> mapFile <-stats|outputFile>\n", output.str());
    }

    TEST(DriverReturnsCorrectValueWithIncorrectMapFileFormat)
    {
        const NativeChar* arguments[4] =
        {
            NativeText("Unused"),
            NativeText("-format=Foo"),
            NativeText("Unused"),
            NativeText("Unused")
        };

        std::stringstream unused;
        CHECK_EQUAL(1, Driver::Run(4, arguments, unused));
    }

    TEST(DriverOutputsCorrectErrorWithIncorrectMapFileFormat)
    {
        const NativeChar* arguments[4] =
        {
            NativeText("Unused"),
            NativeText("-format=Foo"),
            NativeText("Unused"),
            NativeText("Unused")
        };

        std::stringstream output;
        Driver::Run(4, arguments, output);
        CHECK_EQUAL("Unknown map file format.\nUsage: MapFileParser -format=<MSVC|Clang|SNC|GCC> mapFile <-stats|outputFile>\n", output.str());
    }

    TEST(DriverReturnsCorrectValueWithBadInputFile)
    {
        const NativeChar* arguments[4] =
        {
            NativeText("Unused"),
            NativeText("-format=MSVC"),
            NativeText("NonexistentFile"),
            NativeText("Unused")
        };

        std::stringstream unused;
        CHECK_EQUAL(1, Driver::Run(4, arguments, unused));
    }

    TEST(DriverOutputsCorrectErrorWithBadInputFile)
    {
        const NativeChar* arguments[4] =
        {
            NativeText("Unused"),
            NativeText("-format=MSVC"),
            NativeText("NonexistentFile"),
            NativeText("Unused")
        };

        std::stringstream output;
        Driver::Run(4, arguments, output);
        CHECK_EQUAL("Map file NonexistentFile cannot be opened.\n", output.str());
    }
}

#endif // ENABLE_UNIT_TESTS
