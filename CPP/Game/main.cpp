#include<iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#define DELTA 200 /// Time Quantum in ms (e.g. 40ms for 25FPS)
#define STRIDE 2
using namespace std;
void nextFrame(int waitTimems=DELTA){
	this_thread::sleep_for(chrono::milliseconds(waitTimems));
	return;
}

void clearScreen(int waitTimems=DELTA){
	nextFrame(waitTimems);
	cout << "\033[2J\033[H"; // Clear screen
}

class Dog{
	private:
		int startPos, endPos;
		/*********/
		int findPoseNext(int currPos,int stride=STRIDE){
			return((currPos-stride)>0? currPos-stride: currPos);
		}
		/*********/
		string placement(int pos,string look){
			string padding(pos, ' ');
			stringstream ss(look);
			string line, result;
	    	while (getline(ss, line)) {result += padding + line + "\n";}
	    	return(result);
		}
		/*********/
		int run1(int pos){
			string look="   __\no-''|\\____/)=\n \\_/|_)     )\n    \\   __  \\\n    (_\\    (_\\\n";
			string output= placement(pos,look);
			cout <<output<< endl;
			int nextPos=findPoseNext(pos);
			return(nextPos);
		}
		/*********/
		int run2(int pos){
			string look="   __\no-''|\\_____/)=\n \\_/|_)     )\n   |   __  |\n   (_|   (_|\n";
			string output= placement(pos,look);
			cout <<output<< endl;
			int nextPos=findPoseNext(pos);
			return(nextPos);
		}
		/*********/
		int run3(int pos){
			string look="   __\no-''|\\_____/)=\n \\_/|_)     )\n   /   __  /\n  (_/   (_/\n";
			string output= placement(pos,look);
			cout <<output<< endl;
			int nextPos=findPoseNext(pos);
			return(nextPos);
		}
	public:
		/*********/
		bool isDead(){
			return(false);
		}
		void running(int startPos,int till){
			int nextPos=startPos;
			for(int i=0;i<till;i++){
				clearScreen();
				this->run1(nextPos);
				clearScreen();
				nextPos=findPoseNext(nextPos);
				this->run2(nextPos);
				clearScreen();
				nextPos=findPoseNext(nextPos);
				this->run3(nextPos);
			}
		}
};

int main(){
	Dog woof;
	clearScreen(0);
	woof.running(100,100);
	//clearScreen();
}