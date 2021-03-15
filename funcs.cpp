#include <iostream>
#include <cctype>
#include "funcs.h"

std::string removeLeadingSpaces(std::string line) {
    std::string output = "";
    bool leading = true;
    
    for (int i = 0; i < line.length(); i++) {
        if (!(leading && isspace(line[i]))) {
            output = output + line[i];
            leading = false;
        }
    }
    
    return output;
}