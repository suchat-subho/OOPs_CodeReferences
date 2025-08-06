/*
 * Program: Function Pointer Example
 * Description: This program demonstrates the use of function pointers in C.
 * It defines several functions with the same signature and allows the user
 * to dynamically choose which function to call at runtime by entering its name.
 * The program then uses a function pointer to execute the selected function.
 */

#include <stdio.h>
#include <string.h> // Required for strcmp

// Define a few sample functions with the same signature
// (void return type, no parameters)
void say_hello() {
    printf("Hello from say_hello()!\n");
}

void say_goodbye() {
    printf("Goodbye from say_goodbye()!\n");
}

void show_info() {
    printf("This is the show_info() function.\n");
}

int main() {
    // Declare a function pointer.
    // It points to a function that returns void and takes no arguments.
    void (*func_ptr)();

    char function_name[50]; // Buffer to store the user-entered function name

    printf("Enter the name of the function you want to call (say_hello, say_goodbye, show_info):\n");
    // Read the function name from the user
    if (scanf("%49s", function_name) != 1) {
        printf("Error reading input.\n");
        return 1; // Indicate an error
    }

    // Compare the user input with known function names and assign the
    // appropriate function's address to the function pointer.
    if (strcmp(function_name, "say_hello") == 0) {
        func_ptr = say_hello;
    } else if (strcmp(function_name, "say_goodbye") == 0) {
        func_ptr = say_goodbye;
    } else if (strcmp(function_name, "show_info") == 0) {
        func_ptr = show_info;
    } else {
        // Handle cases where the user enters an unknown function name
        printf("Error: Function '%s' not found.\n", function_name);
        return 1; // Indicate an error
    }

    // Call the function using the function pointer
    printf("\nCalling the function via pointer...\n");
    func_ptr(); // This is equivalent to (*func_ptr)();

    return 0; // Indicate successful execution
}
