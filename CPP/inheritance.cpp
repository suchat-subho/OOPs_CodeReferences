#include <iostream>
using namespace std;

class Base {
private:    int priv;         // private: not accessible outside Base
protected:  int prot;         // protected: accessible in derived classes
public:     int pub;          // public: accessible everywhere
    Base() : priv(1), prot(2), pub(3) {}
    void showBase() {
        cout << "Base: priv=" << priv << ", prot=" << prot << ", pub=" << pub << endl;
    }
};

class Derived : public Base {
public:
    void accessMembers() {
        // cout << "priv=" << priv << endl;  // ERROR: private not accessible
        cout << "prot=" << prot << endl;     // Accessible (protected → protected)
        cout << "pub=" << pub << endl;       // Accessible (public → public)
    }
};

int main() {
    Base b;
    b.showBase();
    cout << "Accessing public from Base object: " << b.pub << endl;
    // cout << b.prot << endl;   // ERROR: protected not accessible outside
    // cout << b.priv << endl;   // ERROR: private not accessible outside

    Derived d;
    d.accessMembers();
    cout << "Accessing public from Derived object: " << d.pub << endl;
    // cout << d.prot << endl;   // ERROR: protected still not accessible outside

    return 0;
}
