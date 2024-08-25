#include <bits/stdc++.h>
using namespace std;

int main() {
	queue<int> q;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	//reverse first k elements
	stack<int> s;
	for (int i = 0; i < k; i++) {
		s.push(q.front());
		q.pop();
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	//reverse remaining elements
	for (int i = 0; i < n - k; i++) {
		q.push(q.front());
		q.pop();
	}
	//print queue
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}