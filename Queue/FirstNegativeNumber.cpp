#include <bits/stdc++.h>
using namespace std;

int main(){
	//first negative number in every window of size k
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	//sliding window technique
	queue<int> q;
	vector<int> ans;
	for(int i = 0; i < k; i++){
		if(arr[i] < 0)
			q.push(i);
	}
	for(int i = k; i < n; i++){
		if(!q.empty())
			ans.push_back(arr[q.front()]);
		else
			ans.push_back(0);
		while(!q.empty() && q.front() <= i - k)
			q.pop();
		if(arr[i] < 0)
			q.push(i);
	}
	if(!q.empty())
		ans.push_back(arr[q.front()]);
	else
		ans.push_back(0);
	for(unsigned int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}