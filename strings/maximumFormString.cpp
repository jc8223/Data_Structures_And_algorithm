#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using  namespace std;

int main(){
	vector<string> v = {"0123", "0023", "456", "00182", "940", "002901"};
	int max = INT16_MIN;
	for(int i = 0 ; i < v.size() ; i++){
		int n = stoi(v[i]);
		if(n > max) max = n;
	}	
	cout << max << endl;
	for(int i = 0 ; i < v.size() ; i++){
		int n = stoi(v[i]);
		if(n == max){
			cout << v[i] << endl;
			break;
		}
	}
	return 0 ;
}