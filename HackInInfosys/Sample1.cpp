#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int Energy;
	cin >> Energy;
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int t = 0;
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	int count = Energy;
	for(int i=0; i<n; i++){
		if(arr[i] <= count){
			count = count - arr[i];
			t++;
		}
		else{
			continue;
		}
	}
	for(int i=0; i<n; i++){
		if(count == 0){
			break;
		}
		else if(arr[i] <= count){
			count = count - arr[i];
			t++;
		}
		else{
			continue;
		}
	}
	cout << endl;
	if(count == 0){
		cout << t;
	}
	else{
		cout << -1;
	}
	return 0;
}