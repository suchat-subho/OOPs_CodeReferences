/*

// It is a good practice to use #pragma once to prevent multiple
// inclusions of the header file within the same translation unit.

// The #pragma once directive ensures that this header file is
 included and processed only a single time, even if it is
 referenced multiple times in other source files.
*/
#pragma once

#include <iostream>

// Declare a function here.
void print_message();

// Now, let's create the main source file (e.g., "main.cpp")
// to show how #pragma once works.
// We will intentionally include the header file twice.
// Without #pragma once (or traditional include guards), this
// would cause a compiler error due to re-declaration.
// With #pragma once, the compiler knows to ignore the second inclusion.

// -- Begin of main.cpp content --

// #include "my_header.h"
// #include "my_header.h"

// void print_message() {
//     std::cout << "This message is from the header." << std::endl;
// }

// int main() {
//     print_message();
//     return 0;
// }

// -- End of main.cpp content --
