#include<iostream>
using namespace std;
class complex {
   int real, img;
   public:
      complex() {real = 0; img = 0;}
      complex(int r, int i) {real = r; img = i;}
      void print(){ cout << real <<"+"<< img<<"i"<<endl;}

      complex operator + (const complex &obj){
         complex res;
         cout<<"(Call by Ref)"<<endl;
         res.real = real + obj.real;
         res.img = img + obj.img;
         return res;
      }
      complex operator + (complex obj){
         complex res;
         cout<<"(Call by Value)"<<endl;
         res.real = real + obj.real;
         res.img = img + obj.img;
         return res;
      }
};

int main(){
   complex c1(10, 5), c2(2, 4);
   complex c3 = c1 + c2; 
   c3.print();
}
