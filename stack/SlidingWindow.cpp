#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextGreaterIdx(vector<int> arr ,int n){
	// next greater element idx
	vector<int> ans(n);
	stack<int> s;
	ans[n-1]=n;
	s.push(n-1);
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && arr[s.top()]<=arr[i]){
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
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int n=nums.size();
	vector<int> ans;
	vector<int> nge=NextGreaterIdx(nums,n);
	for(int i=0;i<=n-k;i++){
		int j=i;
		while(nge[j]<i+k){
			j=nge[j];
		}
		ans.push_back(nums[j]);
	}
	return ans;
}

int main(){
	vector<int> arr ={1,3,-1,-3,5,3,6,7};
	//output: [3,3,5,5,6,7]
	int k=3;
	vector<int> ans=maxSlidingWindow(arr,k);
	for(unsigned int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}