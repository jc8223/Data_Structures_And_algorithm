#include<iostream>
using namespace std;

int CountString(int n){
	int *ans = new int[n+1];
	ans[0] = 2;
	ans[1] = 3;
	for(int i=2;i<=n-1;i++){
		ans[i] = ans[i-1] + ans[i-2];
	}
	return ans[n-1];
}

int main(){
	int n;
	cin>>n;
	cout<<CountString(n)<<endl;
}