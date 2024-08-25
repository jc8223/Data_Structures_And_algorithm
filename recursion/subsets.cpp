#include <iostream>
#include <string>
#include <vector>

using namespace std;
void subsets(string original,string ans,int idx,vector<string>& v){
	if(idx == original.length()){
		v.push_back(ans);
		return ;
	}
	char ch = original[idx];
	subsets(original,ans+ch,idx+1,v);
	subsets(original,ans,idx+1,v);
}

int main(){
	string str="abc";
	string ans = "";
	vector <string> v;
	subsets(str,ans,0,v);
	int n= v.size();
	for(int i = 0 ; i < n ;i++){
		cout << v[i] << endl;
	}
}