//0/1 knapsack using  dynamic programming vector
#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int W){
	int n = wt.size();
	vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
	for(int i=1; i<=n; i++){
		for(int w=1; w<=W; w++){
			if(wt[i-1] <= w){
				dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
			}else{
				dp[i][w] = dp[i-1][w];
			}
		}
	}
	return dp[n][W];
}

int main(){
	vector<int> wt = {1, 3, 4, 5};
	vector<int> val = {1, 4, 5, 7};
	int W = 7;
	cout<<knapsack(wt, val, W)<<endl;
	return 0;
}