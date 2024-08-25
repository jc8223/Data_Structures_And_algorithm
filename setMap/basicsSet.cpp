#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.insert(50);
	for(int x : s)
		cout<<x<<" ";
	cout<<endl;
	cout<<s.size()<<endl;
	int target = 30;
	if(s.find(target) != s.end())
		cout<<target<<" is present"<<endl;
	else
		cout<<target<<" is not present"<<endl;
	return 0;
}