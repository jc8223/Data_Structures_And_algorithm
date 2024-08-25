#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

void print(stack <int> s){
	//iterative way
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

//previous greater element
stack<int> previousGreater(int arr[],int n){
	stack<int> s;
	stack<int> res;
	for(int i=0;i<n;i++){
		if(s.empty()){
			res.push(-1);
		}
		else if(s.top()>arr[i]){
			res.push(s.top());
		}
		else if(s.top()<=arr[i]){
			while(!s.empty() && s.top()<=arr[i]){
				s.pop();
			}
			if(s.empty()){
				res.push(-1);
			}
			else{
				res.push(s.top());
			}
		}
		s.push(arr[i]);
	}
	print(res);
	return res;
}

int main(){
	int arr[]={100,80,60,70,60,75,85};
	int n=sizeof(arr)/sizeof(arr[0]);
	stack<int> st=previousGreater(arr,n);
	return 0;
}