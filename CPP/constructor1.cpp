#include <iostream>
#include <string>
using namespace std;
class stud{
    public:
    int roll;
    stud(int roll=0){
        this->roll = roll;
    }
};
int main(){
    stud s1;
    stud s2(15);
    cout << s1.roll <<"," << s2.roll;
    return(0);
}
