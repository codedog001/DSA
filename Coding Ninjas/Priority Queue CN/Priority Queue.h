#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class PriorityQueue{

    vector<int> pq;

    public:
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.empty();
    }

    bool getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()) return -1;
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int childIndex = pq.size()-1;
    
        int parentIndex = (childIndex-1)/2;
        while(childIndex > 0 && parentIndex >=0 && pq[parentIndex] > pq[childIndex]){
            swap(pq[parentIndex], pq[childIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }

        cout<< "Element " << data << " Inserted" << endl;
    }

	int removeMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		
        int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;
	}
}