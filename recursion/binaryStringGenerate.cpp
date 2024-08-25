#include <iostream>
#include <string>
using  namespace std;

void GenerateString(int n, string s){
	if(s.length()==n) {
		cout << s << endl;
		return;
	}
	GenerateString(n,s+'0');
	if(s=="" || s[s.length()-1]=='0') GenerateString(n,s+'1');
}

int main(){
	int n = 4;
	string ans;
	GenerateString(n,ans);
}