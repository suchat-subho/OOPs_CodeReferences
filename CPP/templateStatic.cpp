#include<iostream>
using namespace std;

template<class T, class U>
void fun(const T& x,const U& y){
  static int i = 10;
  cout << ++i<<endl;
  return;
}
  


int main()  {
   fun<char, char>('a','b');
   fun<char, char>('x','y') ;
   fun<int, double>(2,2.0);
   return 0;
}

