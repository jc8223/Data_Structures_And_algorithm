#include <iostream>

using namespace std;


//vector shift
void shift(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    if (k < 0) {
        k = k + n;
    }
    reverse(arr.begin(), arr.begin() + n - k);
    reverse(arr.begin() + n - k, arr.end());
    reverse(arr.begin(), arr.end());
}

//vector pair remove
void removePair(vector<int>& arr) {
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        if (st.empty()) {
            st.push(arr[i]);
        } else {
            if (st.top() < arr[i]) {
                st.pop();
            } else {
                st.push(arr[i]);
            }
        }
    }
    while (!st.empty()) {
        arr.push_back(st.top());
        st.pop();
    }
    reverse(arr.begin(), arr.end());
}
//xor
int unique(vector<int>& arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}


int main() {
    int rows, cols;
    cin >> rows;
    cin >> cols;

    int** arr = new int*[rows];  // Creating an array of row pointers

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];  // Creating each row dynamically
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    int maxr = rows - 1;
    int minr = 0;
    int maxc = cols - 1;
    int minc = 0;

    while (minr <= maxr && minc <= maxc) {
        // Right
        for (int j = minc; j <= maxc; j++) {
            cout << arr[minr][j] << " ";
        }
        minr++;

        // Down
        for (int i = minr; i <= maxr; i++) {
            cout << arr[i][maxc] << " ";
        }
        maxc--;

        // Left
        if (minr <= maxr) {
            for (int j = maxc; j >= minc; j--) {
                cout << arr[maxr][j] << " ";
            }
			maxr--;
        }

        // Up
        if (minc <= maxc) {
            for (int i = maxr; i >= minr; i--) {
                cout << arr[i][minc] << " ";
            }
            minc++;
        }
    }
    return 0;
}