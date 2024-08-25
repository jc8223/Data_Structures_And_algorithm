#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool panlindrome(string original,int start, int end){
	if(start > end) return true;
	if(original[start]!=original[end]) return false;
	else return panlindrome(original,start+1,end-1);
}

int main(){
	string str="ada";
	cout << panlindrome(str,0,str.size()-1);
}