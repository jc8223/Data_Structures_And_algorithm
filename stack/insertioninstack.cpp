#include<iostream>
#include<stack>
using namespace std;

void insertAtBottum(stack<int> &s,int x)
{
	stack<int> a;
	while(!s.empty())
	{
		a.push(s.top());
		s.pop();
	}
	s.push(x);
	while(!a.empty())
	{
		s.push(a.top());
		a.pop();
	}
}

void insertAtIdx(stack<int> &s,int x,int idx){
	unsigned int n=idx;
	stack<int> a;
	while(a.size()>n)
	{
		a.push(s.top());
		s.pop();
	}
	s.push(x);
	while(!a.empty())
	{
		s.push(a.top());
		a.pop();
	}
}

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
	//insertion in stack at bottom
	insertAtBottum(s,40);
	cout<<endl;
	print(s);
	insertAtIdx(s,50,2);
	cout<<endl;
	print(s);
}