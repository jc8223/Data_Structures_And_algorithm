#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
	set<int> s;
	s.insert(1);
	s.insert(4);
	s.insert(3);
	// first element print
	cout << *s.begin() << endl;
	// pop first element
	s.erase(s.begin());
	// use of emplace
	s.insert(7);
	// print all elements
	for(auto i : s)
		cout<<i<<" ";

		//emplace vs insert
		// emplace is faster than insert
	map<int,int> m;
	m[1] = 100;
	m[3] = 200;
	m[2] = 300;
	for(auto i : m)
		cout << i.first << " " << i.second << endl;
	return 0;
}