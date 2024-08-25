#include<iostream>
using namespace std;

//Implementation of Queue using Linked List
class Node{
public:
	int data;
	Node *next;
};

class Queue{
private:
	Node *front;
	Node *rear;
	int size;
public:
	Queue(){
		front = rear = NULL;
	}
	void enqueue(int x){
		//insert at tail
		Node *t = new Node;
		if(t == NULL){
			cout << "Queue is Full" << endl;
		}
		else{
			t->data = x;
			t->next = NULL;
			if(front == NULL){
				front = rear = t;
			}
			else{
				rear->next = t;
				rear = t;
			}
		}
	}
	int dequeue(){
		//delete from head
		int x = -1;
		Node *p;
		if(front == NULL){
			cout << "Queue is Empty" << endl;
		}
		else{
			p = front;
			front = front->next;
			x = p->data;
			delete p;
		}
		return x;
	}
	void display(){
		Node *p = front;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.display();
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.display();
	return 0;
}
