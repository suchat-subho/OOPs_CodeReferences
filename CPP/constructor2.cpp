
#include <iostream>
class B {
public:
	B() {std::cout << "BC." << std::endl;}
	~B() {std::cout << "BD." << std::endl;}
	void sBF() {std::cout << "B::sBF." << std::endl;}
};
class D : public B {
private:
	int* d;
public:
	D() : d(new int[10]) {
       	std::cout << "DC. All. 10 i." << std::endl;
      	for(int i = 0; i < 10; ++i) d[i] = i;
	}
	~D() { delete[] d; std::cout << "DD. F. 10 i." << std::endl;
	}
	void sDF() {std::cout << "D::sDF." << std::endl;}
};
int main() {
	std::cout << "---Scenario---" << std::endl;
	B* p = new D();
	p->sBF();
	std::cout << "\nDeleting..." << std::endl;
	delete p;
	std::cout << "\n---End---" << std::endl;
	return 0;
}

