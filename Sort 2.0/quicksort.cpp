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
	swap(v[pivotIndex], v[pivot]);
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

void quicksort(vector<int> &v, int left, int right){
	if(left >= right) return;
	int pivot = partition(v, left, right);
	quicksort(v, left, pivot - 1);
	quicksort(v, pivot + 1, right);
}

int main(){
	vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(rand() % 100);
		cout << v[i] << " "; // [0, 100]
	}
	cout<<endl;
	quicksort(v, 0, v.size() - 1);
	for(size_t i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}