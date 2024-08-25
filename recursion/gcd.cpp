#include <iostream>
using  namespace std;

int gcd(int a , int b){
	if(a!=0) return gcd(b%a,a);
	else return a;
}

int main(){
	int a = 10000;
	int b = 10001 ;
	cout << gcd(min(a,b),max(a,b));
}