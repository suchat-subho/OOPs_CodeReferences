#include <iostream>
#include <cstring>
using namespace std;

class Cls {
public:
	char* val;
	int l;

	Cls(const char* s) {
    	  l = strlen(s); val = new char[l + 1]; strcpy(val, s);
    	  cout << "C: '" << val << "'\n";
	}

	~Cls() {if (val) {cout << "D: '" << val << "'\n";delete[] val; val = nullptr;}}

	void foo(const char* sfx) {
    	  int nl = l + strlen(sfx); char* nd = new char[nl + 1];
    	  strcpy(nd, val); strcat(nd, sfx); delete[] val; val = nd;
    	  l = nl;
    	  cout << "A: '" << val << "'\n";
	}
	const char* cs() const {return val;}
};

void pS(Cls s) {
	cout << "P_1: '" << s.cs() << "'\n";
	s.foo(" World!");
	cout << "P_2: '" << s.cs() << "'\n";
}

int main() {
	Cls o("Hello");
	cout << "M_1: '" << o.cs() << "'\n"; pS(o);
	cout << "M_2: '" << o.cs() << "'\n";
	return 0;
}
