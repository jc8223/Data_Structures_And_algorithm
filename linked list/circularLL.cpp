#include <iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;

	Node(int val){
		this->val = val;
		this->next = NULL;
	}
};

class CLL{
	public:
	Node* head;
	Node* tail;
	int size = 0;
	CLL(){
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}
	void insertAtEnd(int val){
		Node* temp = new Node(val);
		if(size==0){
			head = tail = temp;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
		tail->next = head;
		size++;
	}
	void display(){
		Node* temp = head;
		for(int i=0;i<size;i++){
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	void sizeOfCLL(){
		Node* temp = head;
		int size = 0;
		while(temp!=NULL){
			size++;
			temp = temp->next;
		}
	}
	
