#include<queue>

vector<int> kSmallest(int* a, int n, int k) {
    // Write your code here
    if(n<=0) return {};
    priority_queue<int> maxHeap;
    
    for(int i=0; i<n; i++){
        maxHeap.push(a[i]);
        if(maxHeap.size() > k) maxHeap.pop();
    }
    vector<int> res;
    while(!maxHeap.empty()) {
        auto ele = maxHeap.top();
        maxHeap.pop();
        res.push_back(ele);
    }
    return res;
}