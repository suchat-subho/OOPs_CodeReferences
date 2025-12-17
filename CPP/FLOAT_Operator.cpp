#include <iostream>
#include <cmath>
using namespace std;




class FLOAT {
private:
    int mantissa;   // ✔ 0.25 mark: private integer data member
    int exponent;   // ✔ 0.25 mark: private integer data member
// (Total: 0.5 for data members)

    // Manual integer shifting: returns m * 10^n using loop
    /*int shift10(int m, int n) const {
        for (int i = 0; i < n; i++)
            m *= 10;
        return m;
    }*/
    int shift10(int m, int n) const {
        return m * static_cast<int>(pow(10, n));
    }




public:
    // Constructor
    FLOAT(int m = 0, int e = 0) : mantissa(m), exponent(e) {}
// ✔ 0.5 mark: parameterized constructor with default arguments; 0 otherwise




    // Getters
    int getMantissa() const { return mantissa; }   // ✔ 0.25 mark
    int getExponent() const { return exponent; }   // ✔ 0.25 mark
// (Total: 0.5 for getters); 0 void return in getter




    // Setters
    void setMantissa(int m) { mantissa = m; }      // ✔ 0.25 mark
    void setExponent(int e) { exponent = e; }      // ✔ 0.25 mark
// (Total: 0.5 for setters)




    // ========== FLOAT + FLOAT ==========
    FLOAT operator+(const FLOAT &b) const {
        int eX = (exponent < b.exponent) ? exponent : b.exponent;
        // ✔ 0.25 mark: exponent alignment logic


        int shiftA = exponent - eX;
        int shiftB = b.exponent - eX;
//// Please note: The exponent alignment has to be performed before mantissa operation. Mere use of formula may not result in accurate code.


        int mA = mantissa;
        int mB = b.mantissa;


        if (shiftA > 0) mA = shift10(mA, shiftA);
        if (shiftB > 0) mB = shift10(mB, shiftB);
        // ✔ 0.5 mark: integer-based mantissa shifting (no float conversion)


        int mX = mA + mB;   // ✔ 0.25 mark: correct mantissa addition


        return FLOAT(mX, eX);
    }
    // ✔ Total: 1 / 1 mark for operator+; 0.5 /1 if exponent not aligned




    // ========== FLOAT * FLOAT ==========
    FLOAT operator*(const FLOAT &b) const {
        int mX = mantissa * b.mantissa;   // ✔ 0.5 mark
        int eX = exponent + b.exponent;   // ✔ 0.5 mark
        return FLOAT(mX, eX);
    }
    // ✔ Total: 1 / 1 mark for operator*




    // ========== Comparison (integer-based) ==========
    bool operator==(const FLOAT &b) const {
//// Please note: The exponent alignment has to be performed before mantissa operation. Mere use of formula may not result in accurate code.
        int eX = (exponent < b.exponent) ? exponent : b.exponent;


        int shiftA = exponent - eX;
        int shiftB = b.exponent - eX;


        int mA = mantissa;
        int mB = b.mantissa;


        if (shiftA > 0) mA = shift10(mA, shiftA);
        if (shiftB > 0) mB = shift10(mB, shiftB);


        return (mA == mB);   // ✔ 1 mark: integer-based comparison
    }
    // ✔ Total: 1 / 1 mark; 0/1 if incorrect




    // ========== Assignment ==========
    void operator=(const FLOAT &b) {
        if (this != &b) {   // ✔ 0.5 mark: self-assignment check
            mantissa = b.mantissa;
            exponent = b.exponent;
        }
        //return *this;       // ✔ 0.5 mark: returns reference
    }
    // ✔ Total: 1/1 mark, 0.5/1 if Not appropriate return type (e.g. FLOAT &)




    // FRIENDS for FLOAT op int
    friend FLOAT operator+(const FLOAT &f, int x);   // ✔ 0.5 mark
    friend FLOAT operator*(const FLOAT &f, int x);   // ✔ 0.5 mark
// (Total: 1 / 3 for Section C)




    void print() const {
        cout << mantissa << "e" << exponent;
    }
};




// FLOAT + int
FLOAT operator+(const FLOAT &f, int x) {
    FLOAT temp(x, 0);       // ✔ 0.5 mark: int converted to FLOAT
    return f + temp;        // ✔ 0.5 mark: reuse FLOAT + FLOAT logic
}
// ✔ Total: 1 / 1 mark; 0/1 if incorrect




// FLOAT * int
FLOAT operator*(const FLOAT &f, int x) {
    return FLOAT(f.mantissa * x, f.exponent);   // ✔ 1 mark
}
// ✔ Total: 1 / 1 mark


// ===================== MAIN =====================
int main() {
    FLOAT A(10234, -3);   // 10.234
    FLOAT B(-56, -2);     // -0.56


    cout << "A = "; A.print(); cout << endl;
    cout << "B = "; B.print(); cout << endl;


    FLOAT C = A + B;      // ✔ 0.5 mark
    cout << "C=A+B[" << 10.234 + -.56 << "]:";
    C.print();
    cout<<endl; 
    FLOAT D = A * B;      // ✔ 0.5 mark
    cout << "D=A*B [" << 10.234 * -.56 << "]:";
    D.print();cout<<endl;
    // (Total: 1 / 4 for FLOAT–FLOAT arithmetic)


    cout << "\n\n(A == B)?  " << (A == B ? "YES" : "NO") ;
    cout <<endl;
    // ✔ 1 mark: comparison demonstration


    FLOAT E;
    E = A;                // ✔ 1 mark: assignment operator demo
    cout << "E=A :";
    E.print();cout<<endl;
    /*
    if ((E = A) > 0) { 
    	cout << "E=A : Test case" <<endl; 
    }
    */


    FLOAT F = A + 5;      // ✔ 0.5 mark
    cout << "F [" << 10.234 + 5 << "]:";
    F.print();cout<<endl;

    FLOAT G = B * 3;      // ✔ 0.5 mark
    cout << "G [" << -.56 * 3 << "]:";
    G.print();cout<<endl;
    // (Total: 1 / 4 for FLOAT–int arithmetic)


    cout << endl;
    return 0;
}
