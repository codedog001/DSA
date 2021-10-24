    int mergeStones(vector<int>& stones, int k) {
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto &g:stones) minHeap.push(g);
        while(minHeap.size()>1){
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();
            cost += a+b;
        }
        return cost+=minHeap.top();
    }