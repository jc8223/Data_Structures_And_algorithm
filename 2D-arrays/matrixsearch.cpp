#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows;
    cin >> cols;
    int array[rows][cols];
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            cin >> array[i][j];
        }
    }
    cout << "Target element";
    int target;
    cin >> target;
    int i = 0 ;
    int j = cols ;
    while (i < rows || j <= cols){
        if(array[i][j] > target){
            j--;
        }
        else if(array[i][j] < target){
            i++;
        }
        else{
            cout << "Founded" << endl;
			cout << i << " " << j << endl;
            break;
        }
    }
    return 0 ;
}