How is this class working?
// typedef pair<int, int> ppi;
class CustomGreat{
    public:
    bool operator () (ppi &a, ppi &b){
        
        // cout << "Pair a: <" << a.first << "," << a.second << "> b: <" << b.first << "," << b.second << "> ";
        //Compare frequency 
        if(a.first > b.first) {
            // cout << "true" << endl;
            return true;
        }
        //If frequency of both elements is equal, compare the values
        else if(a.first == b.first){
            // cout << "Freq equal - true "<< endl;
            if(a.second < b.second) return true;
        }
        // cout<< "False" << endl;
        return false;
    }
};

// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& a) {
//         if(a.empty()) return a;
//         priority_queue<ppi, vector<ppi>, CustomGreat> minHeap;
//         map<int, int> m;
//         for(auto &c: a) m[c]++;
//         for(auto i=m.begin(); i!=m.end(); i++){
//             ppi temp;
//             // cout << "ELE: " << i-> first << endl;
//             temp.first = i->second;
//             temp.second = i->first;
            
            
//             minHeap.push(temp);
//         }
//         int j=0;
//         while(!minHeap.empty()){
//             for(int i=0; i<minHeap.top().first; i++) {
//                 a[j] = minHeap.top().second;
//                 j++;
//             }
//             minHeap.pop();
//         }
//         return a;
//     }
// };