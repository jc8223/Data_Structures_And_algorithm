#include <iostream>

using namespace std;

int main(){
	int arr[] = {1,2,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0 ; i < size ; i++){
		for(int k = i ; k < size ;k++){
			for(int j = i ; j<= k;j++){
				cout << arr[j] ;
			}
			cout << endl;
		}
	}
}