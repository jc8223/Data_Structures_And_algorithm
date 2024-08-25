#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using  namespace std;

//Given two strings s and t, determine if they are isomorphic

int main(){
	string s;
	string t;
	getline(cin,s);
	getline(cin,t);
	vector<int> v (150,1000);
	int flag = 0 ;
	int check = 0 ;
	if(s.length() == t.length()){
		for(int i = 0 ; i < s.length() ; i++){
			int idx = (int)s[i];
			if(v[idx] == 1000){
				v[idx] = (int)s[i] - (int)t[i];
			}
			else{
				if(v[idx] != (int)s[i] - (int)t[i]){
					flag = 1 ;
					break;
				}
			}
		}
		for (int i = 0 ; i < 150 ; i++){
			v[i] = 1000;
		}
		for(int i = 0 ; i < s.length() ; i++){
			int idx = (int)t[i];
			if(v[idx] == 1000){
				v[idx] = (int)t[i] - (int)s[i];
			}
			else{
				if(v[idx] != (int)t[i] - (int)s[i]){
					check = 1 ;
					break;
				}
			}
		}
	}
	else{
		check = 1;
		flag = 1 ;
	}
	if(check == 0 && flag == 0 ){
		cout << "isomorphic" << endl;
	}
	else{
		cout << "Not Isomorphics" ;
	}
}