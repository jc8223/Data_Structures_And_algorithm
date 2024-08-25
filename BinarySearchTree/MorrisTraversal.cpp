#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data){
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* BuildTree(int inorder[],int n){
	queue<Node*> q;
	Node* root = newNode(inorder[0]);
	q.push(root);
	int i = 1;
	int j = 2;
	while(i < n && !q.empty()){
		Node* current = q.front();
		q.pop();
		Node* left ;
		Node* right = newNode(inorder[j]);
		if(inorder[i] != INT_MIN) left = newNode(inorder[i]);
		else left = NULL;
		current->left = left;
		if (inorder[j] != INT_MIN && j!=n) right = newNode(inorder[j]);
		else right = NULL;
		current->right = right;
		if(left != NULL) q.push(left);
		if(right != NULL) q.push(right);
		i+=2;
		j+=2;
	}
	return root;
}

void levelOrderTraversal(Node* root){
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* current = q.front();
		cout<<current->data<<" ";
		if(current->left != NULL)
			q.push(current->left);
		if(current->right != NULL)
			q.push(current->right);
		q.pop();
	}
}

void MorrisTraversal(Node* root){
	Node* current = root;
	while(current != NULL){
		if(current->left == NULL){
			cout<<current->data<<" ";
			current = current->right;
		}
		else{
			Node* predecessor = current->left;
			while(predecessor->right != NULL && predecessor->right != current)
				predecessor = predecessor->right;
			if(predecessor->right == NULL){
				predecessor->right = current;
				current = current->left;
			}
			else{
				predecessor->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
}

int main(){
	int ArrayofGraph[] = {10,5,15,2,7,12,20,1,3,6,8,11,13,18,25};
	int n = sizeof(ArrayofGraph)/sizeof(ArrayofGraph[0]);
	Node* root = BuildTree(ArrayofGraph,n);
	levelOrderTraversal(root);
	cout<<endl;
	MorrisTraversal(root);
	cout<<endl;
}