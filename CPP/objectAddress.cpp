#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>

using namespace std;

// ============================================================
// GLOBAL DATA
// ============================================================

int globalVar = 100;
static int staticGlobal = 200;

const int globalConst = 300;

void globalFunction(){
    cout << "Inside globalFunction()\n";
}

// ============================================================
// CLASS
// ============================================================

class Demo{
public:
    int x;
    double y;
    char c;

    Demo(int a, double b, char ch): x(a), y(b), c(ch){
    }

    void memberFunction(){
        cout << "Inside Demo::memberFunction()\n";
        cout << "this = " << this << '\n';
    }

    static void staticMemberFunction(){
        cout << "Inside Demo::staticMemberFunction()\n";
    }

    virtual void virtualFunction(){
        cout << "Inside Demo::virtualFunction()\n";
    }
};
// ============================================================
// HELPER
// ============================================================
void printAddress(const char* name, const void* address){
    cout << left << setw(30)
         << name
         << " : " << address << '\n';
}
// ============================================================
// MAIN
// ============================================================

int main(){
    cout << "====================================================\n";
    cout << "        C++ MEMORY ADDRESS DEMONSTRATION\n";
    cout << "====================================================\n\n";

    // --------------------------------------------------------
    // 1. GLOBAL / STATIC VARIABLES
    // --------------------------------------------------------

    cout << "1. GLOBAL / STATIC DATA\n";
    cout << "----------------------------------------------------\n";

    printAddress("&globalVar", &globalVar);
    printAddress("&staticGlobal", &staticGlobal);
    printAddress("&globalConst", &globalConst);

    cout << '\n';

    // --------------------------------------------------------
    // 2. LOCAL VARIABLES - STACK
    // --------------------------------------------------------

    cout << "2. LOCAL VARIABLES (STACK)\n";
    cout << "----------------------------------------------------\n";

    int local1 = 10;
    int local2 = 20;

    double local3 = 3.14;
    char local4 = 'A';

    printAddress("&local1", &local1);
    printAddress("&local2", &local2);
    printAddress("&local3", &local3);
    printAddress("&local4", &local4);

    cout << '\n';

    // --------------------------------------------------------
    // 3. POINTER VARIABLES THEMSELVES
    // --------------------------------------------------------

    cout << "3. POINTER VARIABLES\n";
    cout << "----------------------------------------------------\n";

    int* p = &local1;

    printAddress("&p (address of pointer)", &p);
    printAddress("p  (address it stores)", p);

    cout << '\n';

    // --------------------------------------------------------
    // 4. REFERENCES
    // --------------------------------------------------------

    cout << "4. REFERENCES\n";
    cout << "----------------------------------------------------\n";

    int& ref = local1;

    printAddress("&ref", &ref);
    printAddress("&local1", &local1);

    cout << "ref value = " << ref << '\n';

    cout << "\nNotice that &ref == &local1\n";
    cout << "A reference is an alias, not a separate C++ object.\n";

    cout << '\n';

    // --------------------------------------------------------
    // 5. DYNAMIC MEMORY - HEAP
    // --------------------------------------------------------

    cout << "5. DYNAMIC MEMORY (HEAP)\n";
    cout << "----------------------------------------------------\n";

    int* heapInt = new int(123);

    double* heapDouble = new double(456.78);

    printAddress("heapInt variable", &heapInt);
    printAddress("heapInt -> object", heapInt);

    printAddress("heapDouble variable", &heapDouble);
    printAddress("heapDouble -> object", heapDouble);

    cout << '\n';

    // --------------------------------------------------------
    // 6. OBJECT ON STACK
    // --------------------------------------------------------

    cout << "6. OBJECT ON STACK\n";
    cout << "----------------------------------------------------\n";

    Demo obj(10, 20.5, 'X');

    printAddress("&obj", &obj);

    cout << '\n';

    cout << "Object members:\n";

    printAddress("&obj.x", &obj.x);
    printAddress("&obj.y", &obj.y);
    printAddress("&obj.c", &obj.c);

    cout << '\n';

    cout << "Offsets inside object:\n";

    uintptr_t base = reinterpret_cast<uintptr_t>(&obj);

    cout << "x offset = "
         << reinterpret_cast<uintptr_t>(&obj.x) - base
         << " bytes\n";

    cout << "y offset = "
         << reinterpret_cast<uintptr_t>(&obj.y) - base
         << " bytes\n";

    cout << "c offset = "
         << reinterpret_cast<uintptr_t>(&obj.c) - base
         << " bytes\n";

    cout << "sizeof(Demo) = "
         << sizeof(Demo)
         << " bytes\n";

    cout << '\n';

    // --------------------------------------------------------
    // 7. OBJECT ON HEAP
    // --------------------------------------------------------

    cout << "7. OBJECT ON HEAP\n";
    cout << "----------------------------------------------------\n";

    Demo* heapObj = new Demo(100, 200.5, 'Z');

    printAddress("heapObj variable", &heapObj);
    printAddress("heapObj -> object", heapObj);

    printAddress("heapObj->x", &heapObj->x);
    printAddress("heapObj->y", &heapObj->y);
    printAddress("heapObj->c", &heapObj->c);

    cout << '\n';

    // --------------------------------------------------------
    // 8. THIS POINTER
    // --------------------------------------------------------

    cout << "8. THIS POINTER\n";
    cout << "----------------------------------------------------\n";

    cout << "Calling obj.memberFunction():\n";

    obj.memberFunction();

    cout << '\n';

    cout << "Calling heapObj->memberFunction():\n";

    heapObj->memberFunction();

    cout << '\n';

    // --------------------------------------------------------
    // 9. MEMBER FUNCTION ADDRESS
    // --------------------------------------------------------

    cout << "9. FUNCTION ADDRESSES\n";
    cout << "----------------------------------------------------\n";

    cout << "Address of global function:\n";
    cout << reinterpret_cast<const void*>(&globalFunction)
         << '\n';

    cout << '\n';

    cout << "Address of member function:\n";

    /*
       A pointer-to-member-function is NOT necessarily
       the same size/representation as a normal function pointer.
    */

    void (Demo::*memberPtr)() = &Demo::memberFunction;

    cout << "sizeof(memberPtr) = "
         << sizeof(memberPtr)
         << " bytes\n";

    cout << '\n';

    cout << "Address of static member function:\n";

    cout << reinterpret_cast<const void*>(
                &Demo::staticMemberFunction)
         << '\n';

    cout << '\n';

    // --------------------------------------------------------
    // 10. FUNCTION POINTER
    // --------------------------------------------------------

    cout << "10. FUNCTION POINTER\n";
    cout << "----------------------------------------------------\n";

    void (*functionPtr)() = &globalFunction;

    printAddress("functionPtr variable", &functionPtr);

    cout << "functionPtr -> function = "
         << reinterpret_cast<const void*>(functionPtr)
         << '\n';

    cout << '\n';

    functionPtr();

    cout << '\n';

    // --------------------------------------------------------
    // 11. VIRTUAL FUNCTION / VTABLE
    // --------------------------------------------------------

    cout << "11. VIRTUAL FUNCTION / VTABLE\n";
    cout << "----------------------------------------------------\n";

    cout << "Address of obj:\n";
    cout << &obj << '\n';

    /*
       Because Demo has a virtual function, most implementations
       place a hidden vptr inside the object.

       This is implementation-specific and is NOT guaranteed
       by the C++ standard.
    */

    void** rawObject = reinterpret_cast<void**>(&obj);

    cout << "First machine word of object = "
         << rawObject[0]
         << '\n';

    cout << "This is typically the vptr (vtable pointer).\n";
    cout << "It is implementation/compiler dependent.\n";

    cout << '\n';

    obj.virtualFunction();

    cout << '\n';

    // --------------------------------------------------------
    // 12. ARRAY ADDRESSES
    // --------------------------------------------------------

    cout << "12. ARRAY ADDRESSES\n";
    cout << "----------------------------------------------------\n";

    int array[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++){
        cout << "&array[" << i << "] = "
             << static_cast<void*>(&array[i])
             << '\n';
    }

    cout << '\n';

    cout << "Difference between elements:\n";

    cout << "address difference = "
         << reinterpret_cast<char*>(&array[1])
            - reinterpret_cast<char*>(&array[0])
         << " bytes\n";

    cout << '\n';

    // --------------------------------------------------------
    // 13. STRING LITERAL
    // --------------------------------------------------------

    cout << "13. STRING LITERAL\n";
    cout << "----------------------------------------------------\n";

    const char* text = "Hello World";

    printAddress("text variable", &text);
    printAddress("string literal", text);

    cout << '\n';

    // --------------------------------------------------------
    // 14. LAMBDA OBJECT
    // --------------------------------------------------------

    cout << "14. LAMBDA OBJECT\n";
    cout << "----------------------------------------------------\n";

    auto lambda = [](){
        cout << "Inside lambda\n";
    };

    printAddress("&lambda object", &lambda);

    cout << "sizeof(lambda) = "
         << sizeof(lambda)
         << " bytes\n";

    lambda();

    cout << '\n';

    // --------------------------------------------------------
    // 15. STACK POINTER / FRAME POINTER
    // --------------------------------------------------------

    cout << "15. CPU STACK / FRAME POINTER\n";
    cout << "----------------------------------------------------\n";

#if defined(__x86_64__) || defined(__aarch64__)

    uintptr_t stackPointer = 0;
    uintptr_t framePointer = 0;

#if defined(__x86_64__)

    asm volatile(
        "mov %%rsp, %0"
        : "=r"(stackPointer)
    );

    asm volatile(
        "mov %%rbp, %0"
        : "=r"(framePointer)
    );

#elif defined(__aarch64__)

    asm volatile(
        "mov %0, sp"
        : "=r"(stackPointer)
    );

    asm volatile(
        "mov %0, x29"
        : "=r"(framePointer)
    );

#endif

    cout << "Stack Pointer (SP) = 0x"
         << hex << stackPointer
         << dec << '\n';

    cout << "Frame Pointer (FP/BP) = 0x"
         << hex << framePointer
         << dec << '\n';

#else

    cout << "SP/FP demonstration not implemented for this CPU.\n";

#endif

    cout << '\n';

    // --------------------------------------------------------
    // 16. ADDRESS COMPARISON
    // --------------------------------------------------------

    cout << "16. ADDRESS RANGE COMPARISON\n";
    cout << "----------------------------------------------------\n";

    cout << "Global variable : "
         << &globalVar << '\n';

    cout << "Stack variable  : "
         << &local1 << '\n';

    cout << "Heap object     : "
         << heapObj << '\n';

    cout << "Function        : "
         << reinterpret_cast<const void*>(&globalFunction)
         << '\n';

    cout << '\n';

// --------------------------------------------------------
// 17. MEMORY MAP SUMMARY WITH ACTUAL ADDRESSES
// --------------------------------------------------------

cout << "====================================================\n";
cout << "             MEMORY MAP WITH ADDRESSES\n";
cout << "====================================================\n\n";

cout << hex << showbase;

cout << "        HIGH ADDRESSES\n";
cout << "        +------------------------------------------+\n";
cout << "        |                 STACK                    |\n";
cout << "        |                                          |\n";
cout << "        |  local1       = " << reinterpret_cast<uintptr_t>(&local1) << '\n';
cout << "        |  local2       = " << reinterpret_cast<uintptr_t>(&local2) << '\n';
cout << "        |  local3       = " << reinterpret_cast<uintptr_t>(&local3) << '\n';
cout << "        |  local4       = " << reinterpret_cast<uintptr_t>(&local4) << '\n';
cout << "        |  obj          = " << reinterpret_cast<uintptr_t>(&obj) << '\n';
cout << "        |  SP           = " << stackPointer << '\n';
cout << "        |  FP/BP        = " << framePointer << '\n';
cout << "        +------------------------------------------+\n";
cout << "        |                                          |\n";
cout << "        |                  HEAP                    |\n";
cout << "        |                                          |\n";
cout << "        |  heapInt      = " << reinterpret_cast<uintptr_t>(heapInt) << '\n';
cout << "        |  heapDouble   = " << reinterpret_cast<uintptr_t>(heapDouble) << '\n';
cout << "        |  heapObj      = " << reinterpret_cast<uintptr_t>(heapObj) << '\n';
cout << "        +------------------------------------------+\n";
cout << "        |                                          |\n";
cout << "        |               BSS / DATA                |\n";
cout << "        |                                          |\n";
cout << "        |  globalVar    = " << reinterpret_cast<uintptr_t>(&globalVar) << '\n';
cout << "        |  staticGlobal = " << reinterpret_cast<uintptr_t>(&staticGlobal) << '\n';
cout << "        |  globalConst  = " << reinterpret_cast<uintptr_t>(&globalConst) << '\n';
cout << "        +------------------------------------------+\n";
cout << "        |                                          |\n";
cout << "        |                TEXT / CODE              |\n";
cout << "        |                                          |\n";
cout << "        |  globalFunction = "
     << reinterpret_cast<uintptr_t>(&globalFunction) << '\n';
cout << "        +------------------------------------------+\n";
cout << "        LOW ADDRESSES\n";

cout << dec << noshowbase;
    // --------------------------------------------------------
    // CLEANUP
    // --------------------------------------------------------

    delete heapInt;
    delete heapDouble;
    delete heapObj;

    return 0;
}