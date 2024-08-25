#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
	vector<int> pq;
	public:
	PriorityQueue(){
	}
	bool isEmpty(){
		return pq.size()==0;
	}
	int getSize(){
		return pq.size();
	}
	int getMin(){
		if(isEmpty()){
			return 0;
		}
		return pq[0];
	}

	void printHeap(){
		for(unsigned int i=0;i<pq.size();i++){
			cout<<pq[i]<<" ";
		}
		cout<<endl;
	}
	
	void insert(int element){
		pq.push_back(element);
		//up-heapify
		int childIndex=pq.size()-1;
		while(childIndex>0){
			int parentIndex=(childIndex-1)/2;
			if(pq[childIndex]<pq[parentIndex]){
				int temp=pq[childIndex];
				pq[childIndex]=pq[parentIndex];
				pq[parentIndex]=temp;
			}
			else{
				break;
			}
			childIndex=parentIndex;
		}
	}
	int removeMin(){
		if(isEmpty()){
			return 0;
		}
		int ans=pq[0];
		pq[0]=pq[pq.size()-1];
		pq.pop_back();
		int parentIndex=0;
		unsigned int leftChildIndex=2*parentIndex+1;
		unsigned int rightChildIndex=2*parentIndex+2;
		while(leftChildIndex<pq.size()){
			int minIndex=parentIndex;
			if(pq[minIndex]>pq[leftChildIndex]){
				minIndex=leftChildIndex;
			}
			if(rightChildIndex<pq.size() && pq[minIndex]>pq[rightChildIndex]){
				minIndex=rightChildIndex;
			}
			if(minIndex==parentIndex){
				break;
			}
			int temp=pq[minIndex];
			pq[minIndex]=pq[parentIndex];
			pq[parentIndex]=temp;
			parentIndex=minIndex;
			leftChildIndex=2*parentIndex+1;
			rightChildIndex=2*parentIndex+2;
		}
		return ans;
	}

	int peek(){
		if(isEmpty()){
			return 0;
		}
		return pq[0];
	}
	void heapify(int i){
		int left=2*i+1;
		int right=2*i+2;
		int minIndex=i;
		if(left<pq.size() && pq[left]<pq[minIndex]){
			minIndex=left;
		}
		if(right<pq.size() && pq[right]<pq[minIndex]){
			minIndex=right;
		}
		if(minIndex!=i){
			int temp=pq[i];
			pq[i]=pq[minIndex];
			pq[minIndex]=temp;
			heapify(minIndex);
		}
	}

	maxHeap(vector<int> v){
		pq=v;
		for(int i=(pq.size()-2)/2;i>=0;i--){
			heapify(i);
		}
	}
};
int main(){
	PriorityQueue pq;
	pq.insert(100);
	pq.insert(10);
	pq.insert(15);
	pq.insert(4);
	pq.insert(17);
	pq.insert(21);
	pq.insert(67);
	pq.insert(1);
	cout<<pq.getSize()<<endl;
	cout<<pq.getMin()<<endl;
	cout<<"print Heap"<<endl;
	pq.printHeap();
	pq.removeMin();
	pq.printHeap();
	vector<int> v;
	v = {1,2,3,4,5,6,7,8,9};
	pq.maxHeap(v);
	pq.printHeap();
	return 0;
}