#include <iostream>
using namespace std;

class Node{
public:
	int val;
	Node* left;
	Node* right;
	Node(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};
void Preorder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->val<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root){
	if(root == NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->val<<" ";
	Inorder(root->right);
}

void Postorder(Node* root){
	if(root == NULL){
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->val<<" ";
}


int main(){
	Node* a = new Node(1);
	Node* b = new Node(2);
	Node* c = new Node(3);
	Node* d = new Node(4);
	Node* e = new Node(5);
	Node* f = new Node(6);
	Node* g = new Node(7);
	//contruct the tree
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	cout<<"Preorder: ";
	Preorder(a);
	cout<<endl;
	cout<<"Inorder: ";
	Inorder(a);
	cout<<endl;
	cout<<"Postorder: ";
	Postorder(a);
	return 0;
}

