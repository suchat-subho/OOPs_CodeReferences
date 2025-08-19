#include <iostream>
using namespace std;
int main() {
    int* ptr = new int(100); 
    int& ref = (* new int(300)); 
    cout << "ref: " << ref <<"*ptr:"<< *ptr << endl; // Output: 100
    ref = 200;
    cout << "ref: " << ref <<"*ptr:"<< *ptr << endl; // Output: 100    
    delete ptr; 
    ptr = nullptr; // Good practice to prevent dangling pointers   
    cout <<"*ptr:"<< *ptr << endl;
    cout << "ref: " << ref << endl;
    return 0;
}