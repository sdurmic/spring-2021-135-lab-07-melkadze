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

int countChar(std::string line, char c) {
    int count = 0;
    
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == c)
            count++;
    }
    
    return count;
}