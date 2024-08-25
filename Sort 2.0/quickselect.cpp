#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int left, int right){
	int pivot = v[(left + right) / 2];
	int count=0;
	for(int i = left ; i< right ; i++){
		if(v[i] <= pivot){
			count++;
		}
	}
	int pivotIndex = left + count ;
	swap(v[pivot] ,v[pivotIndex]);
	int i = left, j = right;
	while(i <= j){
		while(v[i] < pivot) i++;
		while(v[j] > pivot) j--;
		if(i <= j){
			swap(v[i], v[j]);
			i++;
			j--;
		}
	}
	return pivotIndex;
}

int KthSmallest(vector<int> &v, int left, int right, int k){
	int pivot = partition(v, left, right);
	if(pivot+1 == k) return v[pivot];
	else if(pivot+1 >k) return KthSmallest(v, left, pivot - 1,k);
	else return KthSmallest(v, pivot + 1, right,k);
}

int main(){
	vector<int> v = {5, 2, 1, 3, 6, 4};
	int k = 3;
	cout << KthSmallest(v, 0, v.size() - 1, k) << endl;
	return 0;
}