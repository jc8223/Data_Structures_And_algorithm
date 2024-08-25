//next greater element
#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={100,80,60,70,60,75,85};
	int n=sizeof(arr)/sizeof(arr[0]);
	// -1 80 70 75 75 85 -1
	for(int i = 0 ; i < n ;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	//prev Greater element
	int ans[n];
	// using stack
	stack<int> s;
	ans[0]=-1;
	s.push(0);
	for(int i=1;i<n;i++){
		while(!s.empty() && arr[s.top()]<=arr[i]){
			s.pop();
		}
		if(s.size()==0){
			ans[i]=-1;
		}
		else{
			ans[i]=s.top();
		}
		s.push(i);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}