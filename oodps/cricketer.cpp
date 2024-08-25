#include <iostream>
#include <string>
using namespace std;

class Cricketer{
	int NoofTestMatches;
	int Average;
	int age;
	string name;

	public:
	void getcricketers(){
		cout << "Enter the name of the cricketer: ";
		getline(cin,name);
		cout << "Enter the age of the cricketer: ";
		cin >> age;
		cout << "Enter the number of test matches played by the cricketer: ";
		cin >> NoofTestMatches;
		cout << "Enter the average of the cricketer: ";
		cin >> Average;
	}
	void print(){
		cout << name;
		cout << age;
		cout << NoofTestMatches;
		cout << Average;
	}
};

int main(){
	Cricketer C[20];
	for(int i = 0; i < 20; i++){
		C[i].getcricketers();
	}
	for(int i = 0; i < 20; i++){
		C[i].print();
	}
	return 0;
}

//[9,1,4,7,3,-1,0,5,8,-1,6]
// 0 1 2 3 4  5 6 7 8 9 10
// sort
// -1 -1 0 1 3 4 5 6 7 8 9