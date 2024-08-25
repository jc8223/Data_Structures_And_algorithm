#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int a, b, l;
        cin >> a >> b >> l;
        int k = 0;
        unordered_set<int> s;
        int x = log(l) / log(a);
        int y = log(l) / log(b);
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                int p = pow(a, i) * pow(b, j);
                if (p <= l && l % p == 0) {
                    k++;
                    s.insert(p);
                }
            }
        }
        cout << k << endl;
    }
    return 0;
}