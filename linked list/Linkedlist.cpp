#include<iostream>
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
void display(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void insertAtEnd(Node* &head, int val){
	Node* temp = new Node(val);
	if(head==NULL){
		head = temp;
	}
	else{
		Node* curr = head;
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
	
}

int main(){
	Node* head = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);
	head->next = second;
	second->next = third;
	display(head);
	insertAtEnd(head, 40);
	display(head);
	return 0;
}