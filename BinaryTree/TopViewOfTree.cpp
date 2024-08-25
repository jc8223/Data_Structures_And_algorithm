#include <iostream>
#include <unordered_map>
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

void Topview(Node* root){
	if(root == NULL)
		return;	
	queue<pair<Node*,int>> q;
	unordered_map<int,int> m;
	pair<Node*,int> p;
	p.first = root;
	p.second = 0;
	q.push(p);
	while(q.size() > 0){
		Node* temp = (q.front()).first;
		int level = (q.front()).second;
		q.pop();
		if(m.find(level) == m.end())
			m[level] = temp->data;
		if(temp->left != NULL){
			p.first = temp->left;
			p.second = level-1;
			q.push(p);
		}
		if(temp->right != NULL){
			p.first = temp->right;
			p.second = level+1;
			q.push(p);
		}
	}
	int minLevel = INT_MAX;
	int maxLevel = INT_MIN;
	for(auto i : m){
		if(i.first < minLevel)
			minLevel = i.first;
		if(i.first > maxLevel)
			maxLevel = i.first;
	}
	for(int i = minLevel; i <= maxLevel; i++)
		cout<<m[i]<<" ";
	cout<<endl;
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

int main(){
	int inorder[] = {1,2,3,4,5,6,7};
	int n = sizeof(inorder)/sizeof(inorder[0]);
	Node* root = BuildTree(inorder,n);
	Topview(root);
	return 0;
}