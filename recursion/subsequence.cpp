#include <iostream>
#include <string>
#include <vector>

using namespace std;
void subsets(int arr[] ,int n,int idx,vector <int> v,int k ){
	if(idx==n ) {
		if(v.size()==k){
			int c = v.size();
			for(int i = 0 ; i < c ;i++){
				cout << v[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	subsets(arr,n,idx+1,v,k);
	v.push_back(arr[idx]);
	subsets(arr,n,idx+1,v,k);
}

int main(){
	int arr[] = {1,2,3,4,5};
	int k = 3;
	int size = sizeof(arr)/sizeof(arr[0]);
	vector <int> v;
	subsets(arr,size,0,v,k);

}