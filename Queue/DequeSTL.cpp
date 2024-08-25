#include <iostream>
#include <deque>
using namespace std;

void display(deque<int> dq){
	deque<int>::iterator it;
	for(it = dq.begin(); it != dq.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

int main(){
	deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_front(40);
	dq.push_front(50);
	dq.push_front(60);
	display(dq);
	return 0;
}