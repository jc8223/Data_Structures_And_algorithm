#include <iostream>
using  namespace std;

void hamoi(int n , char a, char b,char c){
	if(n==0) return ;
	hamoi(n-1,a,c,b);
	cout << a << "->" << c << endl;
	hamoi(n-1,b,a,c);
}

int main(){
	int n = 3;
	hamoi(n , 'A' , 'B' , 'C');
	return 0;
}