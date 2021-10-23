Logic: Calculate the abs difference of a[i] - x and form a pair of it with a[i].
E.g: arr = [1,2,3,4,5], k = 4, x = 3
a[i] = 2
abs(a[i]-x) => abs(2-3) = 1
Pair(1, 2) will be formed -> Store it in max heap, in max heap the highest element comes at 
the top, so the pair with highest abs difference will be at the top.

Pair with lower abs difference will remain at bottom, keep pushing pair until heap.size()<=k, 
and pop when size becomes greater than k.

Naturally, the pair with higher abs difference will get popped first, and k pairs that remain 
in heap until the end will be answer.

Code:

 vector<int> findClosestElements(vector<int>& a, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> res;
        for(auto &ele:a){
            pair<int, int> temp;
            temp.first = abs(ele-x);
            temp.second = ele;
            maxHeap.push(temp);
            
            if(maxHeap.size() > k) maxHeap.pop();
        }
        
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(res.begin(), res.end());
        
        return res;
    }