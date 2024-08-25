#include <bits/stdc++.h>
using  namespace std;

void display(queue<int> q){
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main(){
	queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	stack<int> st;
	int n = q.size();
	for(int i = 0; i < n/2 ; i++){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		q.push(st.top());
		st.pop();
	}
	for(int i = 0; i < n/2 ; i++){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		q.push(st.top());
		st.pop();
		q.push(q.front());
		q.pop();
	}
	//reverse the queue
	while(q.size() != 0){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		q.push(st.top());
		st.pop();
	}
	display(q);
	return 0;
}