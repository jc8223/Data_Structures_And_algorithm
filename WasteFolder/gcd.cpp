#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>

// Function to check if the GCD array is non-decreasing
bool valid(vector<int> &a) {
    int n = a.size();
    vector<int> g(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        g[i] = __gcd(a[i], a[i + 1]);
    }
    for (int i = 1; i < n - 1; ++i) {
        if (g[i] < g[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to solve the problem
void solve(int ttc) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> g(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        g[i] = __gcd(a[i], a[i + 1]);
    }

    int idx = -1;
    for (int i = 1; i < n - 1; ++i) {
        if (g[i] < g[i - 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "YES" << endl;
        return;
    }

    for (int j = max(0, idx - 1); j <= min(n - 1, idx + 1); ++j) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (i != j) {
                v.push_back(a[i]);
            }
        }
        if (valid(v)) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i);
    }
    return 0;
}
