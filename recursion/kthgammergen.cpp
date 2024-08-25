#include <iostream>
using  namespace std;

int KthGrammer(int n , int k){
	if(n==1) return 0;
	if(k%2==0){
		int ret = KthGrammer(n-1,k/2);
		if(ret == 0) return 1;
		else return 0;
	}
	else if(k%2!=0) {
		return KthGrammer(n-1,(k/2)+1);
	}
}

int main(){
	int n = 4;
	int k = 4;
	cout << KthGrammer(n,k);
}