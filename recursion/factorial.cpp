#include<iostream>
using  namespace std;

int fact(int x){
	int n = x;
	if(n==0) return 1;
	return n*fact(n-1);
}

int main(){
	cout << fact(5);
}