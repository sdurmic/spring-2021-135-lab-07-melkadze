#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("[A: removeLeadingSpaces] Do nothing") {
    CHECK(removeLeadingSpaces("no_spaces") == "no_spaces");
    CHECK(removeLeadingSpaces("spaces, none of which are leading or trailing") == "spaces, none of which are leading or trailing");
    CHECK(removeLeadingSpaces("no leading spaces, but normal and trailing spaces   ") == "no leading spaces, but normal and trailing spaces   ");
}

TEST_CASE("[A: removeLeadingSpaces] Remove spaces") {
    CHECK(removeLeadingSpaces("    leading_spaces_only") == "leading_spaces_only");
    CHECK(removeLeadingSpaces("         leading spaces and spaces") == "leading spaces and spaces");
    CHECK(removeLeadingSpaces("    leading and trailing spaces   ") == "leading and trailing spaces   ");
}

TEST_CASE("[B: countChar] Counting chars") {
    CHECK(countChar("{{{sequential", '{') == 3);
    CHECK(countChar("empty", '}') == 0);
    CHECK(countChar("}}}}}", '}') == 5);
    CHECK(countChar("{{{nonsequential{{{{{", '{') == 8);
}