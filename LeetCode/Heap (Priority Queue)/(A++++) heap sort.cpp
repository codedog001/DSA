#include<iostream>
using namespace std;

void createHeapOfArrayElements(int* a, int n){
    for(int i=1; i<n; i++){
        int childInd = i;
        while(childInd > 0){
            int parentInd = (childInd - 1)/2;
            if(a[parentInd] > a[childInd]) swap(a[childInd], a[parentInd]);
            else break;
            childInd = parentInd;
        }
    }
}

void removeMinNtimes(int* pq, int n){
    
    int size = n;
    while(size > 1) {
		swap(pq[0], pq[size-1]);

		size--;

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;

		while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) minIndex = leftChildIndex;
			
			if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) minIndex = rightChildIndx;
			
			if(minIndex == parentIndex) break;
            
			swap(pq[parentIndex], pq[minIndex]);

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
	}
}
void heapSort(int a[], int n) {
    createHeapOfArrayElements(a,n);
    removeMinNtimes(a,n);
}