/*
 * Program: Stringizing Operator Example
 * Description: This program demonstrates the use of the stringizing operator (#)
 * in C preprocessor macros. The '#' operator converts a macro argument into
 * a string literal during the preprocessing phase, before compilation.
 * This is distinct from runtime string manipulation (like strcmp).
 */

#include <stdio.h>

// Define a macro that uses the stringizing operator (#)
// The #x converts the argument 'x' into a string literal.
#define PRINT_VALUE(x) printf("The value of " #x " is %d\n", x)

// Another example: concatenating strings using ## (token pasting) and #
#define DEBUG_PRINT(var, val) printf("DEBUG: " #var " = %d, " #val " = %s\n", var, val)

int main() {
    printf("Start Program\a\n");
    int my_integer = 100;
    float pi_value = 3.14159f;
    char my_char = 'A';
    const char* my_string = "Hello Macro";

    // When PRINT_VALUE(my_integer) is called, the preprocessor
    // replaces it with: printf("The value of " "my_integer" " is %d\n", my_integer);
    // The string literals are then concatenated by the compiler.
    PRINT_VALUE(my_integer);

    // You can use it with different types, but the format specifier must match
    printf("The value of " #pi_value " is %.2f\n", pi_value);
    printf("The value of " #my_char " is %c\n", my_char);
    printf("The string " #my_string " contains: %s\n", my_string);

    int count = 5;
    DEBUG_PRINT(count, "items"); // Example using DEBUG_PRINT macro

    return 0;
}
