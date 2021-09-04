class Solution {
public:
    
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
    //We are maintaining hash set for each key value like for 0:<hash set> [5,2], for 1:[2,3]. Hash set will only keep unique elements. So its size of each hash set will tell unique minutes of that user.
        
    unordered_map<int, unordered_set<int>> m;
    vector<int> res(k);
    for (auto &l : logs){
        m[l[0]].insert(l[1]);
    }
        // vector<unordered_set<int>> v;
    // for(auto &g : m){
    //     v.push_back(g.second);
    // }
    //     unordered_set<int> o = v[0];
    //     for(auto &x:o){
    //         cout << "ELE: " << x << " ";
    //     }
    
    for (auto &p : m)
        ++res[p.second.size() - 1];
    return res;
}
};