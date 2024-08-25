#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> v;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // find the maximum element in the vector
    int max = *max_element(v.begin(), v.end());

    vector<int> ans;
    for (int j = 1; j <= max; j++) {
        if (s.find(j) == s.end()) {
            ans.push_back(j);
        }
    }

	for (std::vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << ans[v[i] - 1] << endl;
	}
    return 0;
}
