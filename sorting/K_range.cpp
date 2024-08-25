#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int main(){
	vector <int> v = {5,2,10};
	int n = v.size();
	sort(v.begin(),v.end());
	
	//vector size
	int kmin = INT16_MIN;
	int kmax = INT16_MAX;
	for(int i = 0 ; i < n-1;i++){
		if(v[i] >= v[i+1]){
			kmin = max(kmin,(v[i]+v[i+1])/2);
		}
		else{
			kmax = min(kmax,(v[i]+v[i+1])/2);
		}
	}
	cout << "The range K is :[" << kmin << "," << kmax << ']';
}