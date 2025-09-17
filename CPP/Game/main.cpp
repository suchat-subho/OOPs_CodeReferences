#include<iostream>
#include <string>
#include <sstream>
using namespace std;

class character{

	int startPos, endPos;
	int findPoseNext(int currPos){
		return(currPos);
	}
	public:
		/*********/
		bool isDead(){
			return(false);
		}
		/*********/
		int run3(int pos){
			string look="    __\no-''|\\_____/)=\n \\_/|_)     )\n   /   __   \\\n  (_/  (_/\n";
			string padding(pos, ' ');
			stringstream ss(look);
			string line, result;
    		while (getline(ss, line)) {result += padding + line + "\n";}	
			cout <<result<< endl;
			int nextPos=findPoseNext(pos);
			return(nextPos);
		}
};

int main(){
	character c;
	c.run3(10);


}