#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    cout << "========================================\n";
    cout << "       INTERESTING COUT EXAMPLES\n";
    cout << "========================================\n\n";


    // --------------------------------------------------
    // 1. cout itself is an object
    // --------------------------------------------------
    cout << "1. ADDRESS OF cout\n";
    cout << "Address of cout: " << &cout << "\n\n";


    // --------------------------------------------------
    // 2. Character vs integer promotion
    // --------------------------------------------------
    cout << "2. CHARACTER VS INTEGER PROMOTION\n";

    cout << "cout << 'A'  : " << 'A' << '\n';
    cout << "cout << +'A' : " << +'A' << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 3. String pointer arithmetic
    // --------------------------------------------------
    cout << "3. STRING POINTER ARITHMETIC\n";

    cout << "\"ABC\"       : " << "ABC" << '\n';
    cout << "\"ABC\" + 1   : " << "ABC" + 1 << '\n';
    cout << "\"ABC\" + 2   : " << "ABC" + 2 << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 4. Array indexing can be reversed
    // --------------------------------------------------
    cout << "4. REVERSED ARRAY INDEXING\n";

    cout << "\"Hello\"[1]   : " << "Hello"[1] << '\n';
    cout << "1[\"Hello\"]   : " << 1["Hello"] << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 5. Address of a string literal
    // --------------------------------------------------
    cout << "5. ADDRESS OF STRING LITERAL\n";

    cout << "\"Hello\"       : " << "Hello" << '\n';
    cout << "&\"Hello\"      : " << &"Hello" << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 6. Boolean formatting
    // --------------------------------------------------
    cout << "6. BOOLEAN FORMATTING\n";

    cout << "Default true  : " << true << '\n';
    cout << "Default false : " << false << '\n';

    cout << boolalpha;

    cout << "boolalpha true  : " << true << '\n';
    cout << "boolalpha false : " << false << '\n';

    // Restore default
    cout << noboolalpha;

    cout << '\n';


    // --------------------------------------------------
    // 7. cout remembers formatting state
    // --------------------------------------------------
    cout << "7. COUT REMEMBERS ITS FORMAT\n";

    cout << "Decimal : " << 255 << '\n';

    cout << hex;
    cout << "Hex     : " << 255 << '\n';
    cout << "Still hex: " << 100 << '\n';

    cout << oct;
    cout << "Octal   : " << 255 << '\n';

    cout << dec;
    cout << "Decimal : " << 255 << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 8. cout << cout
    // --------------------------------------------------
    cout << "8. cout << cout\n";

    /*
       cout can be converted to bool to indicate
       whether the stream is in a good state.
    */

    cout << "Stream state as bool: " << boolalpha
         << static_cast<bool>(cout) << '\n';

    cout << noboolalpha;

    cout << '\n';


    // --------------------------------------------------
    // 9. Pointer vs pointed value
    // --------------------------------------------------
    cout << "9. POINTER VS POINTED VALUE\n";

    int x = 100;
    int* p = &x;

    cout << "x       : " << x << '\n';
    cout << "&x      : " << &x << '\n';
    cout << "p       : " << p << '\n';
    cout << "*p      : " << *p << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 10. Different overloads of operator <<
    // --------------------------------------------------
    cout << "10. DIFFERENT TYPES, SAME << OPERATOR\n";

    cout << "int     : " << 42 << '\n';
    cout << "double  : " << 3.14159 << '\n';
    cout << "char    : " << 'X' << '\n';
    cout << "string  : " << "Hello" << '\n';
    cout << "boolean : " << true << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 11. Type of cout
    // --------------------------------------------------
    cout << "11. TYPE OF cout\n";

    cout << "typeid(cout).name(): "
         << typeid(cout).name() << '\n';

    cout << '\n';


    // --------------------------------------------------
    // 12. Chaining
    // --------------------------------------------------
    cout << "12. CHAINING\n";

    cout << "Hello " << "World " << 123
         << " " << 3.14 << '\n';

    cout << "\nConceptually:\n";

    cout << "((cout << \"Hello \") << \"World \") << 123\n";


    cout << "\n========================================\n";
    cout << "              END OF DEMO\n";
    cout << "========================================\n";

    return 0;
}
