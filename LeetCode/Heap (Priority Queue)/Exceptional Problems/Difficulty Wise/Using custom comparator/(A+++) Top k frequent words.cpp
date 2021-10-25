typedef pair<int, string> pi;
typedef pair<int, int> ppi;
class CustomGreat{
    public:
	
	// () operator is overloaded
    bool operator () (pi &a, pi &b){
        //TRUE MEANS NO SWAP
        //Compare frequency 
        if(a.first > b.first) {
            return true;
        }
        //If frequency of both elements is equal, compare the values
        else if(a.first == b.first){
            if(a.second < b.second) return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.empty()) return {};
        unordered_map<string, int> m;
        vector<string> res;
        for(auto &c:words) m[c]++;
        priority_queue<pi, vector<pi>,CustomGreat> minHeap;
        for(auto &d:m) {
            pair temp = {d.second, d.first};
            minHeap.push(temp);
            if(minHeap.size()>k) minHeap.pop();
        }
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};