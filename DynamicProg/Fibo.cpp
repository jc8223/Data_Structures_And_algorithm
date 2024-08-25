#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> dp(n, -1);
	if(n>=1){
		dp[0] = 0;
		dp[1] = 1;
	}
	else{
		cout << "Invalid input" << endl;
		return 0;
	}
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n] << endl;
	return 0;
}