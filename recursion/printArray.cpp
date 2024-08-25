#include <iostream>
using  namespace std;

void Display(int arr[],int pos,int size){
	if(pos == size) return;
	cout << arr[pos] << endl;
	Display(arr,pos+1,size);
}

int main(){
	int arr[]={1,2,3,4,5,6,10};
	int size = sizeof(arr)/sizeof(arr[0]);
	Display(arr,0,size);
}
