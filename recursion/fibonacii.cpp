#include<iostream>
using  namespace std;

int fibo(int x){
	int n = x;
	if(n==1 || n==2) return 1;
	return fibo(n-1) + fibo(n-2);
}

int main(){
	cout << fibo(6);
}