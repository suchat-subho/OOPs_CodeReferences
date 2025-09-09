#include <iostream>
#include <string>
using namespace std;

class MyString {
    string data;
public:
    MyString(const string& s = "") : data(s) {}
    MyString operator<<(const MyString& other) const {return MyString(data + other.data);}
    MyString operator>>(const MyString& other) const {return MyString(other.data+data);}
    void display() const {cout << data << endl;}
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3(" ");

    s3 = s1 << s3 <<s2;
    s2 = s3 >> s2;
    s3.display();
    s2.display();

    return 0;
}
