#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextSmallerIdx(int arr[],int n){
	vector<int> ans(n);
	stack<int> s;
	ans[n-1]=n;
	s.push(n-1);
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && arr[s.top()]>=arr[i]){
			s.pop();
		}
		if(s.size()==0){
			ans[i]=n;
		}
		else{
			ans[i]=s.top();
		}
		s.push(i);
	}
	return ans;
	
}

vector<int> PreviousSmallerIdx(int arr[],int n){
	vector<int> ans(n);
	stack<int> s;
	ans[0]=-1;
	s.push(0);
	for(int i=1;i<n;i++){
		while(!s.empty() && arr[s.top()]>=arr[i]){
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
	return ans;
}

int main(){
	int arr[]={1,8,6,2,5,4,8,3,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i = 0 ; i < n ;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	vector<int> ans1=NextSmallerIdx(arr,n);
	vector<int> ans2=PreviousSmallerIdx(arr,n);
	for(int i=0;i<n;i++){
		cout<<ans1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ans2[i]<<" ";
	}
	cout<<endl;
	int max=0;
	for(int i=0;i<n;i++){
		int area=arr[i]*(ans1[i]-ans2[i]-1);
		if(area>max){
			max=area;
		}
	}
	cout<<max<<endl;
	return 0;
}