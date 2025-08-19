#include <iostream>
#include <string>
using namespace std;
int main() {
    string myName = "John Doe";
    const string &nameRef = myName;
    cout << "Original name: " << nameRef << endl;

    // You can modify the original variable.
    myName = "Jane Doe";
   cout << "After:" << nameRef << endl;
  // You cannot modify the variable through the const reference.
    // nameRef = "Peter Pan";
    nameRef= myName;
    return 0;
}
