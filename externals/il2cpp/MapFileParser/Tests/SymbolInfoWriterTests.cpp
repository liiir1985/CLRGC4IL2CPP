#if ENABLE_UNIT_TESTS

#include <sstream>
#include "Runtime/Testing/Testing.h"
#include "../SymbolInfoWriter.h"

using namespace mapfileparser;

UNIT_TEST_SUITE(SymbolInfoWriterTests)
{
#pragma pack(push, p1, 4)
    struct SymbolInfo
    {
        int64_t address;
        int32_t length;
    };
#pragma pack(pop, p1)

    class SymbolInfoWriterFixture
    {
    public:
        SymbolInfoWriterFixture()
        {
            Symbol codeSymbol1 = { 100, 10, "Symbol1Name", "Symbol1ObjectFile", kSegmentTypeCode };
            Symbol codeSymbol2 = { 200, 20, "Symbol2Name", "Symbol2ObjectFile", kSegmentTypeCode };
            Symbol dataSymbol = { 300, 30, "Symbol3Name", "Symbol3ObjectFile", kSegmentTypeData };

            mapFile.symbols.push_back(codeSymbol1);
            mapFile.symbols.push_back(codeSymbol2);
            mapFile.symbols.push_back(dataSymbol);

            SymbolInfoWriter::Write(output, mapFile);
        }

        int32_t ReadActualNumberOfSymbols()
        {
            int32_t numberOfSymbols = 0;
            output.read(reinterpret_cast<char*>(&numberOfSymbols), sizeof(numberOfSymbols));

            return numberOfSymbols;
        }

        SymbolInfo ReadOneSymbolInfo()
        {
            SymbolInfo symbolInfo;
            output.read(reinterpret_cast<char*>(&symbolInfo), sizeof(symbolInfo));

            return symbolInfo;
        }

        MapFile mapFile;
        std::stringstream output;
    };

    TEST_FIXTURE(SymbolInfoWriterFixture, VerifyOnlySymbolsWithACodeSegmentAreWritten)
    {
        CHECK_EQUAL(2, ReadActualNumberOfSymbols());
    }

    TEST_FIXTURE(SymbolInfoWriterFixture, VerifySymbolInformationForFirstSymbol)
    {
        ReadActualNumberOfSymbols();

        SymbolInfo actualInfo = ReadOneSymbolInfo();

        CHECK_EQUAL(100, actualInfo.address);
        CHECK_EQUAL(10, actualInfo.length);
    }

    TEST_FIXTURE(SymbolInfoWriterFixture, VerifySymbolInformationForSecondSymbol)
    {
        ReadActualNumberOfSymbols();
        ReadOneSymbolInfo();

        SymbolInfo actualInfo = ReadOneSymbolInfo();

        CHECK_EQUAL(200, actualInfo.address);
        CHECK_EQUAL(20, actualInfo.length);
    }
}

#endif // ENABLE_UNIT_TESTS
