#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s)
{
	stack<int> a;
	while (s.size() > 0)
	{
		a.push(s.top());
		s.pop();
	}
	while (a.size() > 0)
	{
		cout << a.top() << " ";
		s.push(a.top());
		a.pop();
	}
}

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	print(s);
	stack<int> rt;
	stack<int> gt;
	while(!s.empty())
	{
		gt.push(s.top());
		s.pop();
	}
	while(!gt.empty())
	{
		rt.push(gt.top());
		gt.pop();
	}
	while(!rt.empty())
	{
		s.push(rt.top());
		rt.pop();
	}
	cout<<endl;
	print(s);
}