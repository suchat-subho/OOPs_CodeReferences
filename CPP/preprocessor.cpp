#include <iostream>

// This program demonstrates the use of C++ preprocessor directives:
// #ifdef and #ifndef. These are used for conditional compilation.

// To enable the debug mode, you can uncomment the line below or,
// more commonly, define it during compilation from the command line:
// g++ -DDEBUG_MODE main.cpp -o main

// #define DEBUG_MODE

int main() {
#ifdef DEBUG_MODE
    std::cout << "DEBUG: Debug mode is enabled." << std::endl;
    std::cout << "This message is only compiled when DEBUG_MODE is defined." << std::endl;
#endif // DEBUG_MODE
    std::cout << "This message is always compiled and executed." << std::endl;
#ifndef RELEASE_MODE
    std::cout << "INFO: This is the non-release version." << std::endl;
    std::cout << "This message is compiled because RELEASE_MODE is not defined." << std::endl;
#endif // RELEASE_MODE
    return 0;
}
