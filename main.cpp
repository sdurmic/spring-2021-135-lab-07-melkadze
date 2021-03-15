#include <iostream>
#include "funcs.h"

int main() {
    // read the entire cin input until eos/eof instead of
    // per line or char by using istreambuf_iterator
    std::string input(std::istreambuf_iterator<char>(std::cin), {});
    
    // perform both tasks through one helper function, and print
    std::cout << style(input);
    
    return 0;
}