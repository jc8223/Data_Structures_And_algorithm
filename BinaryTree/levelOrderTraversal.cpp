//level Order traversal of a binary tree using queue

#include<iostream>
#include<queue>
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
//each level sum
void levelOrderTraversal(Node* root){
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int count = q.size();
		int sum = 0;
		while(count--){
			Node* current = q.front();
			sum += current->data;
			if(current->left != NULL)
				q.push(current->left);
			if(current->right != NULL)
				q.push(current->right);
			q.pop();
		}
		cout<<sum<<" ";
	}
}

int main(){
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	levelOrderTraversal(root);
	return 0;
}