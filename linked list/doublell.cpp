#include <iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node* prev;

	Node(int val){
		this->val = val;
		this->next = NULL;
		this->prev = NULL;
	}
};

class DLL{
public:
	Node* head;
	Node* tail;
	int size = 0;
	DLL(){
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
			temp->prev = tail;
			tail = temp;
		}
		size++;
	}
	void display(){
		Node* temp = head;
		while(temp!=NULL){
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	void insertAtBegin(int val){
		Node* temp = new Node(val);
		if(size==0){
			head = tail = temp;
		}
		else{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		size++;
	}
	void insertAt(int idx, int val){
		if(idx<0 || idx>size){
			cout<<"Invalid arguments"<<endl;
			return;
		}
		if(idx==0){
			insertAtBegin(val);
		}
		else if(idx==size){
			insertAtEnd(val);
		}
		else{
			Node* temp = new Node(val);
			Node* curr = head;
			for(int i=0;i<idx-1;i++){
				curr = curr->next;
			}
			temp->next = curr->next;
			curr->next->prev = temp;
			curr->next = temp;
			temp->prev = curr;
			size++;
		}
	}
	void deleteAtBegin(){
		if(size==0){
			cout<<"List is empty"<<endl;
			return;
		}
		else if(size==1){
			head = tail = NULL;
		}
		else{
			head = head->next;
			head->prev = NULL;
		}
		size--;
	}
	void deleteAtEnd(){
		if(size==0){
			cout<<"List is empty"<<endl;
			return;
		}
		else if(size==1){
			head = tail = NULL;
		}
		else{
			tail = tail->prev;
			tail->next = NULL;
		}
		size--;
	}
	void deleteAt(int idx){
		if(idx<0 || idx>=size){
			cout<<"Invalid arguments"<<endl;
			return;
		}
		if(idx==0){
			deleteAtBegin();
		}
		else if(idx==size-1){
			deleteAtEnd();
		}
		else{
			Node* curr = head;
			for(int i=0;i<idx-1;i++){
				curr = curr->next;
			}
			curr->next = curr->next->next;
			curr->next->prev = curr;
			size--;
		}
	}

	void getAt(int idx){
		if(idx<0 || idx>=size){
			cout<<"Invalid arguments"<<endl;
			return;
		}
		Node* curr = head;
		if(idx<size/2){
			for(int i=0;i<idx;i++){
				curr = curr->next;
			}
		}
		else{
			curr = tail;
			for(int i=0;i<size-idx-1;i++){
				curr = curr->prev;
			}
		}
		cout<<curr->val<<endl;
	}
};



int main(){
	DLL* head = new DLL();
	head->insertAtEnd(1);
	head->insertAtEnd(2);
	head->insertAtEnd(3);
	head->display();
	head->insertAtBegin(4);
	head->insertAtBegin(5);
	head->insertAtBegin(6);
	head->display();
	head->insertAt(3, 7);
	head->insertAt(0, 8);
	head->insertAt(7, 9);
	head->display();
	head->deleteAtBegin();
	head->deleteAtBegin();
	head->display();
	head->deleteAtEnd();
	head->deleteAtEnd();
	head->display();
	head->deleteAt(2);
	head->display();
	head->getAt(2);
	head->getAt(0);
	return 0;
}