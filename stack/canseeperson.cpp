#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterIndex(int h[],int n){
	int size=n;
	vector<int> ans(size,0);
	stack<int> st;
	st.push(h[size-1]);

	for(int i=size-2;i>=0;i--){

		int num=0;

		while(!st.empty() && st.top()<h[i]){
			st.pop();
			num++;
		}

		if(!st.empty()){
			num++;
		}

		st.push(h[i]);
		ans[i]=num;

	}

	return ans;
}

int main(){
	int arr[]={10,6,8,5,11,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i = 0 ; i < n ;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	vector<int> ans=nextGreaterIndex(arr,n);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
}