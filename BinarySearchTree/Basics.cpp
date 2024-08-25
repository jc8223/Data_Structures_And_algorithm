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

Node* PredecessorInorder(Node* root){
	if (root == NULL)
		return NULL;
	root = root->left;
	while(root->right != NULL)
		root = root->right;
	return root;
}

Node* SuccessorInorder(Node* root){
	if (root == NULL)
		return NULL;
	root = root->right;
	while(root->left != NULL)
		root = root->left;
	return root;
}

Node* deleteNode(Node* root,int data){
	if(root == NULL)
		return NULL;
	if(root->data > data)
		root->left = deleteNode(root->left,data);
	else if(root->data < data)
		root->right = deleteNode(root->right,data);
	else{
		if(root->left == NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else{
			Node* temp = SuccessorInorder(root);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return root;
}

int main(){
	int ArrayofGraph[] = {1 ,3 ,4 ,5 ,6, 7 ,8 ,10, 11, 13, 14 ,15 ,16, 18 ,19};
	int n = sizeof(ArrayofGraph)/sizeof(ArrayofGraph[0]);
	Node* root = BuildTree(ArrayofGraph,n);
	levelOrderTraversal(root);
	cout<<endl;
	Node* predecessor = PredecessorInorder(root);
	Node* successor = SuccessorInorder(root);
	cout<<predecessor->data<<" "<<successor->data<<endl;
	root = deleteNode(root,8);
	levelOrderTraversal(root);
	return 0;
}
