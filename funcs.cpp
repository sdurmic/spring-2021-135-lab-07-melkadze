#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include "funcs.h"

std::string removeLeadingSpaces(std::string line) 
{
    //creates output variable
    std::string output = ""; 
    bool leading = true;
    //iterate through the loop
    for (int i = 0; i < line.length(); i++) 
    {
        //checks if the character is not leading and not a space
        if (!(leading && isspace(line[i]))) {
            output = output + line[i];
            leading = false;
        }
        //otherwise, "leading" remains true
    }   
    return output;
}

int countChar(std::string line, char c) 
{
    //counts number of c (which is curly brackets in this case)
    int count = 0;
    for (int i = 0; i < line.length(); i++) 
    {
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