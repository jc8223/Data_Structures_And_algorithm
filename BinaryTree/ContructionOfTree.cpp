//Construction of Binary Tree from Preorder and Inorder Traversal using Queue
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<iostream>
#include<queue>
#include<climits>
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

int main(){
	int ArrayofGraph[] = {1,2,3,4,INT_MIN,5,INT_MIN,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,8};
	int n = sizeof(ArrayofGraph)/sizeof(ArrayofGraph[0]);
	Node* root = BuildTree(ArrayofGraph,n);
	levelOrderTraversal(root);
	return 0;
}
