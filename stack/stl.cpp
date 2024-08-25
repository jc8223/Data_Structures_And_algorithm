#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	stack<int> s;
	vector<int> v;
	s.push(10);
	s.push(20);
	s.push(30);

	cout<<s.size()<<endl;
	cout<<s.top()<<endl; 
	stack<int> a;
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		a.push(s.top());
		s.pop();
	}
	while(!a.empty())
	{
		s.push(a.top());
		a.pop();
	}
	return 0;
}