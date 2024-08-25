#include <iostream>
using  namespace std;

int main(){
	int arr[] = {124,152,99,25,178};
	int n = 5;
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	int j = n ;
	while(j>0){
		int mx = INT16_MIN;
		int maxidx = -1;
		for(int i = 0 ; i < n ; i++){
			if(mx<arr[i]){
				mx=arr[i];
				maxidx = i;
			}
		}
		arr[maxidx] = j;
		j--;
	}
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
}