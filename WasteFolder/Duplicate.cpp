#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            s = s.substr(0,i)+s.substr(i+1);
            i--; // Decrement i to account for the removed character
        }
    }
    cout << s;
    return 0 ;
}
//