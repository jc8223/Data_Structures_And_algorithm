//inbuilt piriority queue
#include<iostream>
#include<queue>
using namespace std;

int main(){
	priority_queue<int> pq;
	pq.push(16);
	pq.push(1);
	pq.push(100);
	pq.push(10);
	pq.push(15);
	pq.push(3);
	pq.push(2);
	cout<<pq.size()<<endl;
	cout<<pq.top()<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	return 0;
}