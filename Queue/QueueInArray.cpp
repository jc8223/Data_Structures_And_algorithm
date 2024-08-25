#include<iostream>
#include<queue>
using namespace std;

//Implementation of Queue using Array

class Queue{
public:
	int front;
	int rear;
	int size;
	vector<int> Q;
	Queue(int size){
		this->size = size;
		front = rear = -1;
		Q.resize(size);
	}
	void enqueue(int x){
		if(rear == size-1){
			cout << "Queue is Full" << endl;
		}
		else{
			rear++;
			Q[rear] = x;
		}
	}
	void dequeue(){
		if(front == rear){
			cout << "Queue is Empty" << endl;
		}
		else{
			front++;
		}
	}
	void display(){
		for(int i=front+1; i<=rear; i++){
			cout << Q[i] << " ";
		}
		cout << endl;
	}
	void Size(){
		cout << "Size of Queue is: " << rear-front << endl;
	}

};

int main(){
	Queue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.display();
	q.dequeue();
	q.display();
	q.Size();
	return 0;
}