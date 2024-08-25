#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
	int t;cin>>t;
	for(int i=0;i<t;i++){ 
		int n,m;cin>>n>>m;
		string s;cin>>s;
		unordered_map<char,int> mp;
		mp['A'] = 0;
		mp['B'] = 0;
		mp['C'] = 0;
		mp['D'] = 0;
		mp['E'] = 0;
		mp['F'] = 0;
		mp['G'] = 0;
		for(int i=0;i<n;i++)
			mp[s[i]]++;

		int ans = 0;
		for(auto x:mp){
			if(x.second < m)
			ans = ans + (m-x.second);
		}
		cout<<ans<<endl;
	}
	return 0;
}