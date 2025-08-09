#include<iostream>
using namespace std;

int main(){
	int a[10] = {};
	int b[10];
	for(int i=0; i<10;i++){
		cout<<"a["<< i<<"],="<< a[i]<<endl;
		cout <<"b["<< i << "],="<< b[i]<<endl;
	}
	return 0;
}
