#include <iostream>
using namespace std;
#define GET_VALUE(obj) (obj.value)
class Counter {
    int value;
    public:
        Counter(int v) : value(v) {}
        inline int getValue() const {return value;}
};

int main() {
    Counter c1(10);
    cout << "Counter 1 value = " << c1.getValue() << endl;
    cout << "Macro: " << GET_VALUE(c1) << endl;
    cout << "Sum of values = " << sum << endl;
    return 0;
}
