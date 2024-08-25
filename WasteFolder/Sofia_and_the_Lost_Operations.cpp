#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define pyes cout << "YES" << endl;
#define pno cout << "NO" << endl;

using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m)), b(n, vi(m)), an(n, vi(m));

    // Read matrix a
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Read matrix b
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    int i1 = -1, i2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                i1 = i;
            }
            if (b[i][j] == 1) {
                i2 = i;
            }
        }
    }

    if (i1 == -1 || i2 == -1) {
        pno;
        return 0;
    }

    map<int, int> mp1;
    for (int i = 0; i < m; i++) {
        mp1[b[i2][i]] = i;
    }

    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        if (mp1.find(a[i1][i]) == mp1.end()) {
            pno;
            return 0;
        }
        mp[i] = mp1[a[i1][i]];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            an[i][mp[j]] = a[i][j];
        }
    }

    map<int, int> mp3;
    for (int i = 0; i < n; i++) {
        mp3[b[i][0]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (mp3.find(an[i][0]) == mp3.end()) {
            pno;
            return 0;
        }
        int idx = mp3[an[i][0]];
        for (int j = 0; j < m; j++) {
            if (an[i][j] != b[idx][j]) {
                pno;
                return 0;
            }
        }
    }

    pyes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << an[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
