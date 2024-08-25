#include <bits/stdc++.h>
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

void Helper(Node* root, vector<vector<int>>& ans, int level) {
	if (root == NULL) {
		return;
	}
	
	if (ans.size() <= level) {
		ans.push_back(vector<int>());
	}
	
	ans[level].push_back(root->val);
	
	Helper(root->left, ans, level + 1);
	Helper(root->right, ans, level + 1);
}

void levelOrder(Node* root) {
	vector<vector<int>> ans;
	
	if (root == NULL) {
		return ; // Return an empty vector of vectors if the tree is empty.
	}
	
	Helper(root, ans, 0);
	
	//print the ans
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

void NthLevel(Node* root,int curr,int n){
	if(root == NULL)
		return;
	if(curr == n)
		cout<<root->data<<" ";
	NthLevel(root->left,curr+1,n);
	NthLevel(root->right,curr+1,n);
}

int NoOfLevels(Node* root){
	if(root == NULL)
		return 0;
	int left = NoOfLevels(root->left);
	int right = NoOfLevels(root->right);
	return max(left,right)+1;
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
	levelOrder(a);
	cout<<endl;
	return 0;
}

//tree
//			1					level 1
//		2		3				level 2
//	4	  5	6	  7				level 3
