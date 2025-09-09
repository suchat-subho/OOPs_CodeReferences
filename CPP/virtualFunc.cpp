#include <iostream>
#include <cstring>

class MS {
public:
	char* d;
	int l;

	MS(const char* s) {
    	  l = strlen(s); d = new char[l + 1]; strcpy(d, s);
    	  std::cout << "C: '" << d << "'\n";
	}

	~MS() {
    	  if (d) {std::cout << "D: '" << d << "'\n";delete[] d; d = nullptr;}
	}

	void ap(const char* sfx) {
    	  int nl = l + strlen(sfx); char* nd = new char[nl + 1];
    	  strcpy(nd, d); strcat(nd, sfx); delete[] d; d = nd;
    	  l = nl;
    	  std::cout << "A: '" << d << "'\n";
	}
	const char* cs() const {return d;}
};

void pS(MS s) {
	std::cout << "P_B: '" << s.cs() << "'\n";	s.ap(" World!");
	std::cout << "P_A: '" << s.cs() << "'\n";
}

int main() {
	MS o("Hello");
	std::cout << "M_B: '" << o.cs() << "'\n"; pS(o);
	std::cout << "M_A: '" << o.cs() << "'\n";
	return 0;
}
