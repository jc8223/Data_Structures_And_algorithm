#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>arr[i][j];

    for(int i=0;i<n-1;i++){
        arr[i+1][0] += max(arr[i][1], arr[i][2]);
        arr[i+1][1] += max(arr[i][0], arr[i][2]);
        arr[i+1][2] += max(arr[i][0], arr[i][1]);
    }
    cout<<max(arr[n-1][0], max(arr[n-1][1], arr[n-1][2]))<<endl;
    return 0;
}
// dry run
/*
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
*/
// 46
// 6 7 8
