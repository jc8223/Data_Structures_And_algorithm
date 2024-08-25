#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int II() {
    int x;
    cin >> x;
    return x;
}

tuple<int, int, int> MII() {
    int x, y, z;
    cin >> x >> y >> z;
    return make_tuple(x, y, z);
}

vector<int> LII(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return a;
}

int main() {
    int tcn = II();
    for (int _tcn_ = 0; _tcn_ < tcn; ++_tcn_) {
        int n, f, k;
        tie(n, f, k) = MII();
        vector<int> a = LII(n);

        int favorite_value = a[f - 1];

        sort(a.rbegin(), a.rend());

        if (favorite_value > a[k - 1]) {
            cout << "YES" << endl;
        } else if (favorite_value == a[k - 1]) {
            if (k == n || a[k] != favorite_value) {
                cout << "YES" << endl;
            } else {
                cout << "MAYBE" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}