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

TEST_CASE("[B: indent] Indent") {
    CHECK(indent("int main(){\n// Hi, I'm a program!\nint x = 1; \nfor(int i = 0; i < 10; i++) {\ncout << i;\ncout << endl;\n}\n}") == "int main(){\n\t// Hi, I'm a program!\n\tint x = 1; \n\tfor(int i = 0; i < 10; i++) {\n\t\tcout << i;\n\t\tcout << endl;\n\t}\n}\n");
    CHECK(indent("int justnewline()") == "int justnewline()\n");
    CHECK(indent("closeandopenall{{{{{{{{{{}}}}}}}}}}") == "closeandopenall{{{{{{{{{{}}}}}}}}}}\n");
}

TEST_CASE("[B: style] Style") {
    CHECK(style("        int main(){\n// Hi, I'm a program!\n  int x = 1; \nfor(int i = 0; i < 10; i++) {\ncout << i;\n         cout << endl;\n}\n}") == "int main(){\n\t// Hi, I'm a program!\n\tint x = 1; \n\tfor(int i = 0; i < 10; i++) {\n\t\tcout << i;\n\t\tcout << endl;\n\t}\n}\n");
    CHECK(style("   int justnewline()") == "int justnewline()\n");
    CHECK(style(" closeandopenall{{{{{{{{{{}}}}}}}}}}") == "closeandopenall{{{{{{{{{{}}}}}}}}}}\n");
}