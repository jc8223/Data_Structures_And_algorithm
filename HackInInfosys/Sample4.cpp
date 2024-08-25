#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int changes = 0;
    int left = 0, right = N - 1;
    while (left < right) {
        if (arr[left] != arr[right]) {
            // Make both ends equal
            int diff = abs(arr[left] - arr[right]);
            changes += diff;
            arr[left] = arr[right] = min(arr[left], arr[right]);
        } else {
            // Check if the next element towards the middle is one more than the current element
            if (left + 1 < right && arr[left + 1] != arr[left] + 1) {
                changes += abs(arr[left + 1] - (arr[left] + 1));
                arr[left + 1] = arr[left] + 1;
            }
        }
        left++;
        right--;
    }

    cout << changes << endl;

    return 0;
}
