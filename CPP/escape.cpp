/*
 * Program: C++ Escape Characters Test
 * Description: This program demonstrates the usage and effect of various
 * common escape characters in C++ string literals. Escape characters are
 * special sequences that represent non-printable characters or characters
 * that have special meaning in code (like double quotes).
 */

#include <iostream> // Required for input/output operations (std::cout)

int main() {
    std::cout << "--- Demonstrating Common Escape Characters ---" << std::endl;
    std::cout << std::endl; // Add an extra newline for spacing

    // \n: Newline character - moves the cursor to the beginning of the next line.
    std::cout << "This is line one.\nThis is line two (using \\n)." << std::endl;

    // \a: Audible alert 
    std::cout << "(using \\a)" << std::endl;

    // \t: Horizontal tab - moves the cursor to the next tab stop.
    std::cout << "Column1\tColumn2\tColumn3 (using \\t)" << std::endl;
    std::cout << "Item A\tItem B\tItem C" << std::endl;

    // \v: Vertical tab - moves the cursor to the next vertical tab stop.
    // Behavior can vary widely depending on the terminal/console.
    std::cout << "Line 1\vLine 2 (using \\v - behavior may vary)" << std::endl;

    // \b: Backspace - moves the cursor one position back.
    // Can be used to overwrite characters.
    std::cout << "Hello World\b\b\b\b\b\bGoodbye! (using \\b to backspace)" << std::endl; // Overwrites "World"

    // \r: Carriage return - moves the cursor to the beginning of the current line.
    // Subsequent output overwrites the current line.
    std::cout << "This will be overwritten.\rNew text here! (using \\r)" << std::endl;

    // \f: Form feed - moves the cursor to the start of the next page.
    // Rarely used in console applications; more relevant for printers.
    // Behavior can vary widely depending on the terminal/console.
    std::cout << "Before form feed.\fAfter form feed (using \\f - behavior may vary)" << std::endl;

    // \\: Backslash itself - used to print a literal backslash.
    std::cout << "To print a backslash, use double backslash: C:\\Program Files\\ (using \\\\)" << std::endl;

    // \': Single quote - used to print a literal single quote within character literals.
    // Less common in string literals, but valid.
    std::cout << "He said, 'Hello!' (using \\' - typically for char literals)" << std::endl;
    char single_quote_char = '\''; // Example for char literal
    std::cout << "A single quote character: " << single_quote_char << std::endl;

    // \": Double quote - used to print a literal double quote within string literals.
    std::cout << "She said, \"Welcome!\" (using \\\" for double quotes)" << std::endl;

    // \?: Question mark - used to print a literal question mark.
    // Rarely needed as '?' usually doesn't need escaping, but exists for trigraphs.
    std::cout << "Is this a question\? Yes! (using \\? - rarely needed)" << std::endl;

    // Octal escape sequences: \ooo (where ooo are 1 to 3 octal digits)
    // Represents a character by its ASCII value in octal.
    std::cout << "Octal escape for 'A' (ASCII 65 decimal, 101 octal): \101" << std::endl;
    std::cout << "Octal escape for '!' (ASCII 33 decimal, 041 octal): \041" << std::endl;

    // Hexadecimal escape sequences: \xhh (where hh are 1 or more hexadecimal digits)
    // Represents a character by its ASCII value in hexadecimal.
    std::cout << "Hexadecimal escape for 'B' (ASCII 66 decimal, 42 hex): \x42" << std::endl;
    std::cout << "Hexadecimal escape for '$' (ASCII 36 decimal, 24 hex): \x24" << std::endl;

    std::cout << std::endl;
    std::cout << "--- End of Demonstration ---" << std::endl;

    return 0;
}
