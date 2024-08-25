#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using  namespace std;

int main(){
	vector<string> strs = {"flower", "flow","flight"};
	string s = strs[0];
	int p = 3;
	for(int i = 1 ; i < p ; i++){
		int n = strs[i].size();
		int c = 0 ;
		for (int j = 0 ; j < n ; j++){
			if(s[c]==strs[i][j]){
				c = c + 1 ;
			}
			else{
				for (int k = j ; k < n ; k++){
					s.pop_back();
				}
				break;
			}
		}
	}
	cout << s;
	return 0 ;
}

