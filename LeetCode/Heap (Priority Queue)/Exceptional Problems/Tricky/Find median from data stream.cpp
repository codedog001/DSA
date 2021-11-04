class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int count;
    
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;
        if(count == 1) {
            minHeap.push(num);
            return;
        }
        if(minHeap.top() >= num){
            maxHeap.push(num);
            if(maxHeap.size() - minHeap.size() > 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }else{
            minHeap.push(num);
            if(minHeap.size() - maxHeap.size() > 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        
    }
    
    double findMedian() {
        if(count%2==0){
            return (1.0) * (minHeap.top()+maxHeap.top())/2;
        }else{
            if(minHeap.size() < maxHeap.size()) return maxHeap.top();
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */