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

void DisplayTree(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->val<<" ";
	DisplayTree(root->left);
	DisplayTree(root->right);
}

int SizeOfTree(Node* root){
	if (root==NULL) return 0;
	return 1 + SizeOfTree(root->left)+SizeOfTree(root->right);
}

int SumOfTree(Node* root){
	if(root == NULL){
		return 0;
	}
	return root->val + SumOfTree(root->left) + SumOfTree(root->right);
}

int MaximumOfTree(Node* root){
	if(root == NULL){
		return INT32_MIN;
	}
	int Lmax = MaximumOfTree(root->left);
	int Rmax = MaximumOfTree(root->right);
	return max(root->val, max(Lmax, Rmax));
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
	DisplayTree(a);
	cout<<endl;
	cout<<"Size of Tree: "<<SizeOfTree(a)<<endl;
	cout<<"Sum of Tree: "<<SumOfTree(a)<<endl;
	cout<<"Maximum of Nodes: "<< MaximumOfTree(a);
	return 0;
}