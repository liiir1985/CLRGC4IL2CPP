#if ENABLE_UNIT_TESTS

#include "Asserts.h"
#include <sstream>
#include "Runtime/Testing/Testing.h"

static std::string FormatAssertStringContainsError(const std::string& haystack, const std::string& needle)
{
    std::stringstream message;
    message << "Expected the string:\n";
    message << "'";
    message << haystack;
    message << "'\n";
    message << "to contain:\n";
    message << "'";
    message << needle;
    message << "'\n";
    message << "but it does not.\n";

    return message.str();
}

void AssertStringContains(const std::string& haystack, const std::string& needle)
{
    CHECK_MSG(haystack.find(needle) != std::string::npos, FormatAssertStringContainsError(haystack, needle).c_str());
}

#endif //ENABLE_UNIT_TESTS
