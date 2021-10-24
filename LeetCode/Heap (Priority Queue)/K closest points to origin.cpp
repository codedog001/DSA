Logic: Since the pair is being pushed into max heap, the coordinates having highest distance from origin are at the top, and get popped whenver maxHeap.size() > k, so, pair having lesser distance from origin remain in the heap.

typedef pair<int, vector<int>> ppi;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<ppi> maxHeap;
        vector<vector<int>> res;
        for(auto &c:p){
            int x1 = c[0], y1 = c[1], x2 = 0, y2 = 0;
            int dis = (x2-x1)*(x2-x1) + (y2-y1) *(y2-y1);
            ppi temp = {dis,c};
            maxHeap.push(temp);
            if(maxHeap.size() > k) maxHeap.pop();
        }
        
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};