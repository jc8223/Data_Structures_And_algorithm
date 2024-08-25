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

class LinkedList{
public:
	Node* head;
	Node* tail;
	int size = 0;
	LinkedList(){
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
			curr->next = temp;
			size++;
		}
	}
	void hascycle(){
		Node* slow = head;
		Node* fast = head;
		while(fast!=NULL && fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast){
				cout<<"Cycle detected"<<endl;
				return;
			}
		}
		cout<<"No cycle detected"<<endl;
	}

	void reverseKGroup(Node* head, int k){
		Node* curr = head;
		Node* prev = NULL;
		Node* next = NULL;
		int count = 0;
		while(curr!=NULL && count<k){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		if(next!=NULL){
			head->next = reverseKGroup(next,k);
		}
		return prev;
	}

	void deleteAtBegin(){
		if(size==0){
			cout<<"List is empty"<<endl;
			return;
		}
		else if(size==1){
			delete head;
			head = tail = NULL;
		}
		else{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		size--;
	}

	void DeleteMiddleNode(Node* head){
		//base case
		if(head==NULL || head->next==NULL){
			return;
		}
		Node* slow = head;
		Node* fast = head;
		Node* prev = NULL;
		while(fast!=NULL && fast->next!=NULL){
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = slow->next;
		delete slow;
	}

	void deleteAtEnd(){
		if(size==0){
			cout<<"List is empty"<<endl;
			return;
		}
		else if(size==1){
			delete head;
			head = tail = NULL;
		}
		else{
			Node* curr = head;
			while(curr->next!=tail){
				curr = curr->next;
			}
			delete tail;
			tail = curr;
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
			Node* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			size--;
		}
	}
};

int main(){
	LinkedList* ll = new LinkedList();
	ll->insertAtEnd(10);
	ll->insertAtEnd(20);
	ll->insertAtEnd(30);
	ll->display();
	ll->reverseKGroup(ll->head,2);
	ll->display();
	return 0;
}