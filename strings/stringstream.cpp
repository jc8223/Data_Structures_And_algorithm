#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using  namespace std;

int main(){
	string s;
	string temp;
	getline(cin,s);
	stringstream ss(s);
	vector<string> v;
	while(ss>>temp){
		v.push_back(temp);
	}
	//reverse the string

	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << endl;
	}

	return 0 ;
}