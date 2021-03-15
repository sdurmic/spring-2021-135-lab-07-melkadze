#include <string>
#include <iostream>
#include <sstream>
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

std::string indent(std::string input) {
    std::string output = "";
    int currentIndent = 0;
    
    // make a stringstream to read line by line
    std::istringstream issInput(input);
    
    // start by reading the input line by line, putting a newline after each
    for (std::string line; std::getline(issInput, line); output = output + "\n") {
        // count semicolons
        int openCount = countChar(line, '{');
        int closeCount = countChar(line, '}');
        
        // compensate for starting }, if present
        if (line[0] == '}')
            currentIndent--;
        
        // apply current indent level and add to output
        for (int i = 0; i < currentIndent; i++) {
            output = output + "\t";
        }
        output = output + line;
        
        // set current indent
        currentIndent = currentIndent + openCount - closeCount;
    }
    
    return output;
}

// helper function to combine all of our work
std::string style(std::string input) {
    std::string output = "";
    
    // make a stringstream to read line by line
    std::istringstream issInput(input);
    
    // start by reading the input line by line, putting a newline after each
    for (std::string line; std::getline(issInput, line); output = output + "\n") {
        output = output + removeLeadingSpaces(line);
    }
    
    return indent(output);
}