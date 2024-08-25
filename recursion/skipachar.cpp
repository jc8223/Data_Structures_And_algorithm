#include <iostream>
#include <string>
#include <bits/stdc++.h>
using  namespace std;

void skipchar(string s,string f){
	if(s.length()==0){
		cout << f;
		return;
	}
	char ch=s[0];
	if(ch=='a') {
		skipchar(s.substr(1),f);
	}
	else{
		skipchar(s.substr(1),f+ch);
	}
}
void skipchar2(string s,string f, int idx){
	if(idx == s.length()){
		cout << f;
		return;
	}
	char ch=s[idx];
	if(ch=='a') {
		idx++;
		skipchar2(s,f,idx);
	}
	else{
		idx++;
		skipchar2(s,f+ch,idx);
	}
}

int main(){
	string s="Jatin Kumar Gupta";
	skipchar(s,"");
	cout << endl;
	skipchar2(s,"",0);
}