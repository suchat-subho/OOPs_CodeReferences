/*
 * Program: Stringizing Operator Example
 * Description: This program demonstrates the use of the stringizing operator (#)
 * in C preprocessor macros. The '#' operator converts a macro argument into
 * a string literal during the preprocessing phase, before compilation.
 * This is distinct from runtime string manipulation (like strcmp).
 */

#include <stdio.h>

#define PRINT_VALUE_INT(x) printf("The value of " #x " is %d\n", x)
#define PRINT_VALUE_FLOAT(x) printf("The value of " #x " is %.2f\n", x)
#define PRINT_VALUE_CHAR(x) printf("The value of " #x " is %c\n", x)
#define PRINT_VALUE_STRING(x) printf("The string " #x " contains: %s\n", x)

// Another example: concatenating strings using ## (token pasting) and #
// The #var stringizes the variable name, and #val stringizes the string literal.
#define DEBUG_PRINT(var, val) printf("DEBUG: " #var " = %d, " #val " = %s\n", var, val)

int main() {
    int my_integer = 100;
    float pi_value = 3.14159f;
    char my_char = 'A';
    const char* my_string = "Hello Macro";

    PRINT_VALUE_INT(my_integer);
    PRINT_VALUE_FLOAT(pi_value);
    PRINT_VALUE_CHAR(my_char);
    PRINT_VALUE_STRING(my_string);

    int count = 5;
    DEBUG_PRINT(count, "items"); // Example using DEBUG_PRINT macro

    return 0;
}