#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void display(queue<int> q){
	int back = q.back();
	while(q.front() != back){
		int x = q.front();
		cout << q.front() << " ";
		q.push(x);
		q.pop();
	}
	cout << q.front() << " " << endl;
}

void ReverseDisplay(queue<int> q){
	stack<int> s;
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void RemoveEvenPositionedElement(queue<int> q){
	int n = q.size();
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0){
			q.pop();
		}
		else{
			int x = q.front();
			q.push(x);
			q.pop();
		}
	}
	display(q);
}

int main(){
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	display(q);
	ReverseDisplay(q);
	return 0;
}