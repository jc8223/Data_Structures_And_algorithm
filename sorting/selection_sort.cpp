#include <iostream>
using  namespace std;

int main(){
	int arr[] = {5,4,3,2,1};
	int n = 5;
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	for(int i = 0 ; i < n-1 ; i++){
		int minn = INT32_MAX;
		int minidx = -1 ;
		for(int j = i ; j < n ; j++){//entered into orange box
			if(arr[j] < minn){
				minn = arr[j];
				minidx = j;
			}
		}
		swap(arr[i],arr[minidx]);	
	}
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	return 0 ;
}