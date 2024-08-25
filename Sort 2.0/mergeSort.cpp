#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, vector<int>& b, vector<int>& res) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            res[k++] = b[j++];
        }
        else {
            res[k++] = a[i++];
        }
    }
    while (i < a.size()) {
        res[k++] = a[i++];
    }
    while (j < b.size()) {
        res[k++] = b[j++];
    }
}

void MergeSort(vector<int>& v) {
    int n = v.size();
    if (n == 1) return;
    int n1 = n / 2;
    int n2 = n - n1;
    vector<int> a(v.begin(), v.begin() + n1);
    vector<int> b(v.begin() + n1, v.end());

    // Recursion
    MergeSort(a);
    MergeSort(b);
    merge(a, b, v);
    a.clear();
    b.clear();
}

int main() {
    int arr[] = { 5, 2, 1, 50, 10, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    MergeSort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
