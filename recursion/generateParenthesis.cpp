#include <iostream>
#include <string>
#include <bits/stdc++.h>
using  namespace std;

void GenerateString(int n, string s){
	if(s.length()==2*n && count(s.begin(),s.end(),'(')==count(s.begin(),s.end(),')')) {
		cout << s << endl;
		return;
	}
	else if(s.length()==2*n && count(s.begin(),s.end(),'(')!=count(s.begin(),s.end(),')')) return;
	GenerateString(n,s+'(');
	if(s.length()!=0 ) {
		if(count(s.begin(),s.end(),'(')!=count(s.begin(),s.end(),')')) GenerateString(n,s+')');
	}
}

int main(){
	int n = 3;
	string ans;
	GenerateString(n,ans);
}