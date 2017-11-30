#include "SymbolInfoWriter.h"


namespace mapfileparser
{
    static bool ShouldWriteSymbol(const Symbol& symbol)
    {
        return symbol.segmentType == kSegmentTypeCode;
    }

    void SymbolInfoWriter::Write(std::ostream& out, const MapFile& mapFile)
    {
        int32_t numberOfSymbols = 0;
        for (std::vector<Symbol>::const_iterator iter = mapFile.symbols.begin(); iter != mapFile.symbols.end(); ++iter)
            if (ShouldWriteSymbol(*iter))
                ++numberOfSymbols;

        out.write(reinterpret_cast<const char*>(&numberOfSymbols), sizeof(numberOfSymbols));
        for (std::vector<Symbol>::const_iterator iter = mapFile.symbols.begin(); iter != mapFile.symbols.end(); ++iter)
        {
            if (ShouldWriteSymbol(*iter))
            {
                out.write(reinterpret_cast<const char*>(&iter->start), sizeof(int64_t));
                out.write(reinterpret_cast<const char*>(&iter->length), sizeof(int32_t));
            }
        }
    }
}
