typedef pair<int,int> ppi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int, int> m;
        priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;
        
		//Create a freq. map of all elements of the array
        for(auto &c: a) m[c]++;
        
		//Store pair of element and frequency in the min heap, elements will be sorted based on the frequency. Since it is a min heap, elements with higher frequency will remain at bottom.
        for(auto &c: m){
            ppi temp;
            temp.first = c.second;
            temp.second = c.first;
            
            minHeap.push(temp);
            if(minHeap.size() > k) minHeap.pop();
        }
        
        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};