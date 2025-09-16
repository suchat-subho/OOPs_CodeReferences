#include<iostream>
using namespace std;

class Base{
  int a;
  public:
    Base(int arg){ 
        a=arg;
    }
    void show(){
        cout<<"Base class Constructor Called, a ="<<a;
    }   
};

class Derived: public Base{
    public:
        //Derived(int x):Base(x){ }
};

int main(){
    Derived d;
    //Derived d(6);
    d.show();
    return 0;
}

