T.C: Best explained here: https://leetcode.com/problems/reorganize-string/discuss/113440/Java-solution-PriorityQueue/506565

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> maxHeap;
        unordered_map<char,int> m;
        string res = "";
        for(auto &c:s) {
            m[c]++;
            if(2 * m[c] - 1> s.size()) return "";
        }
        for(auto &d:m){
            pair<int,char> temp = {d.second, d.first};
            maxHeap.push(temp);
        }
        
        while(!maxHeap.empty()){
            auto p = maxHeap.top();
            maxHeap.pop();
            res += p.second;
            if(!maxHeap.empty()){
                auto q = maxHeap.top();
                maxHeap.pop();
                res+=q.second;
                if(q.first > 1) maxHeap.push({q.first-1, q.second});
            }
            if(p.first > 1) maxHeap.push({p.first-1, p.second});
        }
        return res;

    }
};