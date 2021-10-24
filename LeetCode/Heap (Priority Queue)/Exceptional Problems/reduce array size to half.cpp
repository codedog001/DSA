typedef pair<int, int> pi;
class Solution {
public:
    int minSetSize(vector<int>& a) {
        if(a.empty()) return 0;
       priority_queue<pi> maxHeap;
       unordered_map<int, int> m;
       for(auto& c:a) m[c]++;
       for(auto &d: m){
            pi temp = {d.second, d.first};
            maxHeap.push(temp);
       }
       int sizeRemoved = 0, res = 0;
       while(!maxHeap.empty() && sizeRemoved < a.size()/2){
            sizeRemoved += maxHeap.top().first;
            res++;
            maxHeap.pop();
       }
       return res;
    }
};