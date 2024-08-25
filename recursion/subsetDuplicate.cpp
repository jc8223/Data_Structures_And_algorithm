#include <iostream>
#include <string>
#include <vector>
using namespace std;

void subsets(string original,string ans,int idx,vector<string>& v,bool flag){
	if(idx == original.length()){
		v.push_back(ans);
		return ;
	}
	char ch = original[idx];
	if(idx == original.length()-1){
		if(flag==true){
			subsets(original,ans+ch,idx+1,v,true);
			subsets(original,ans,idx+1,v,true);
			return;
		}
	}
	char dh = original[idx+1];
	if(ch==dh){
		if(flag==true)subsets(original,ans+ch,idx+1,v,true);
		subsets(original,ans,idx+1,v,false);
	}
	else{
		if(flag==true){
			subsets(original,ans+ch,idx+1,v,true);
			subsets(original,ans,idx+1,v,true);
		}
	}
	return;
}

int main(){
	string str="aab";
	string ans = "";
	vector <string> v;
	subsets(str,ans,0,v,true);
	int n= v.size();
	for(int i = 0 ; i < n ;i++){
		cout << v[i] << endl;
	}
	return 0;
}