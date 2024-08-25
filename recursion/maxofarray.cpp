#include <iostream>
using  namespace std;

int printmax(int arr[],int n ,int idx){
	if(idx==n) return INT16_MIN;
	return max(arr[idx],printmax(arr,n,idx+1));
}

int main(){
	int arr[]={1,2,3,4,5,6,10};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << printmax(arr,size,0);
	return 0;
}