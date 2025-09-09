#include <iostream>
using namespace std;

int main() {
    int x = 10;

    // Reference to a pointer
    int* p = &x;        // pointer to int
    int*& refToPtr = p; // reference to pointer
    cout << "refToPtr points to value: " << *refToPtr << endl;

    int y = 20;
    refToPtr = &y; // changes p as well, since refToPtr is just an alias of p
    cout << "After refToPtr reassignment, p points to: " << *p << endl;

    // Pointer to a reference (actually pointer to the object being referred)
    int& r = x;     // r is a reference to x
    int* ptrToRef = &r; // pointer to reference is same as pointer to the object
    cout << "ptrToRef points to value: " << *ptrToRef << endl;

    *ptrToRef = 30; // modifies x through the pointer to reference
    cout << "x after modification via ptrToRef: " << x << endl;

    return 0;
}
