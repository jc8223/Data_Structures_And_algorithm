#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int days = 0;
	for(int i=1; i<n+1; i++){
		if(arr[i] <= arr[i-1]){
			int diff = arr[i] - arr[i-1];
			arr[i] -= diff;
			days++;
		}
		cout << days << endl;
	}
	return 0;
}