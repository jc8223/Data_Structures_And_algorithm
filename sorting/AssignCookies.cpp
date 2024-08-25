#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int main(){
	vector <int> greedy = {16,15,14,4};
	vector <int> cookies = {5,6,7,8,9,15,14,13,10,16};
	sort(greedy.begin(),greedy.end());
	sort(cookies.begin(),cookies.end());
	int n = greedy.size();
	int m = cookies.size();
	int i = 0;
	int j = 0;
	int count = 0 ;
	while(i< n && j<m){
		if(greedy[i] >= cookies[i]){
			count++;
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	cout << count;
}