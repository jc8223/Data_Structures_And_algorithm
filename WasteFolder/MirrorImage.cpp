#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums = {0,1,6,8,9};
    vector <int> numsImage = {0,1,9,8,6};
    unordered_map<int,int> m;
    int count = 0 ;
    for(int i = 0 ; i < nums.size(); i++){
        m[nums[i]] = numsImage[i];
    }
    for (int i = 1; i <= n ; i++){
        int num = i;
        string str = to_string(num);
        int br = 0;
        for (int j = 0 ; j < str.length() ; j++){
            int dr = str[j] - '0';
            if (m.find(dr) == m.end()) {
                br = 1;
                break;
            } 
            else {
                str[j] = m[dr] + '0'; 
            }
        }
		reverse(str.begin(),str.end());
        if(br==1) continue;
        if(str != to_string(num))  count++;
    }
    cout << count;
    return 0;
}

//Test Case:
// n = 20
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// count = 1+1+1+1+1+1=6