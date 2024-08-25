#include<iostream>
#include <vector>
using  namespace std;

int main(){
	int arr[] = {1,2,3,10,15,18,20,22};
	int n = 8;
	int x = 16;
	//linear search
	for(int i = 0 ; i< n;i++){
		if(arr[i]>x){
			cout << arr[i-1] << " " << arr[i] << endl;
			break;
		}
	}
	//Binary search
	int lo =0;
	int hi = n-1;
	bool flag = false;
	while(lo < hi){
		int mid = (lo + hi)/2;
		if(arr[mid]== x){
			cout << arr[mid-1];
			flag = true;
		}
		else if(arr[mid] < x){
			lo = mid+1;
		}
		else if(arr[mid] > x){
			hi = mid-1;
		}
	}
	if(flag == false) cout << arr[lo] ;
}