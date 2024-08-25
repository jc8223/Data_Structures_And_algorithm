#include <bits/stdc++.h>
using namespace std;

int main(){   
    int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int dp[n];
		int k = 2;
		while(true){
			for (int i = 0; i < n; i++){
				dp[i] = arr[i]%k;
			}
			sort(dp,dp+n);
			if(dp[0] != dp[n-1]) break;
			else k*=2;
		}
		cout<<k<<endl;
	}
    return 0;     
}