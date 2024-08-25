#include <iostream>
#include <string>
#include <vector>

using namespace std;
void subArray(int arr[] ,int n,int idx,vector <int> v ){
	if(idx==n) {
		int c = v.size();
		for(int i = 0 ; i < c ;i++){
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	subArray(arr,n,idx+1,v);
	if(v.size()==0){
		v.push_back(arr[idx]);
		subArray(arr,n,idx+1,v);
	}
	else if(arr[idx-1]==v[v.size()-1]){
		v.push_back(arr[idx]);
		subArray(arr,n,idx+1,v);
	}
}

int main(){
	int arr[] = {1,2,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	vector <int> v;
	subArray(arr,size,0,v);
	return 0 ;
}