#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	unordered_map<string, int> m;
	pair<string, int> p1;
	p1.first = "Jatin";
	p1.second = 186;
	m.insert(p1);
	pair<string, int> p2;
	p2.first = "Tarun";
	p2.second = 100;
	m.insert(p2);
	pair<string, int> p3;
	p3.first = "varun";
	p3.second = 200;
	m.insert(p3);
	//method 2
	m["Rahul"] = 1;
	m["Rohit"] = 45;
	for(pair<string , int> p : m)
		cout<<p.first<<" "<<p.second<<endl;

	m.erase("Rahul");
	cout<<endl;
	return 0;
}