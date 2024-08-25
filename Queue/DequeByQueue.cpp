#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int data;
	node *next;
};

class Deque{
private:
	node *front;
	node *rear;
	int size;
public:
	Dequeue(){
		front = rear = NULL;
	}
	void pushfront(int val){
		node *t = new node;
		if(t == NULL){
			cout << "Queue is Full" << endl;
		}
		else{
			t->data = val;
			t->next = NULL;
			if(front == NULL){
				front = rear = t;
			}
			else{
				t->next = front;
				front = t;
			}
		}
	}
	void pushrear(int val){
		node *t = new node;
		if(t == NULL){
			cout << "Queue is Full" << endl;
		}
		else{
			t->data = val;
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
	int popfront(){
		int x = -1;
		node *p;
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
	int poprear(){
		int x = -1;
		node *p = front;
		if(front == NULL){
			cout << "Queue is Empty" << endl;
		}
		else{
			while(p->next != rear){
				p = p->next;
			}
			x = rear->data;
			delete rear;
			rear = p;
			rear->next = NULL;
		}
		return x;
	}
	void display(){
		node *p = front;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

};

int main(){
	Deque q;
	q.pushfront(1);
	q.pushfront(2);
	q.pushfront(3);
	q.pushfront(4);
	q.pushfront(5);
	q.pushrear(6);
	q.pushrear(7);
	q.pushrear(8);
	q.pushrear(9);
	q.pushrear(10);
	q.display();
	cout << q.popfront() << endl;
	cout << q.poprear() << endl;
	q.display();
	return 0;
}