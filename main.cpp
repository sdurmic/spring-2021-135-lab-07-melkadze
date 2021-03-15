#include <iostream>
#include "funcs.h"

int main() {
    //std::cout << removeLeadingSpaces("    te st e ");
    std::cout << indent("int main(){\n// Hi, I'm a program!\nint x = 1; \nfor(int i = 0; i < 10; i++) {\ncout << i;\ncout << endl;\n}\n}");
    return 0;
}