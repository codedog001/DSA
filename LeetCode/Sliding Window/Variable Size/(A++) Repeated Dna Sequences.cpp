    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> resset, set;
        vector<string> res;
        if(s.size() < 10) return res;
        for(int i = 0; i <= s.size() - 10; i++){
            string sub = s.substr(i,  10);
            
            if(set.find(sub) != set.end()){
                resset.insert(sub);
            }
            set.insert(sub);
        }
        for(auto &s:resset) res.push_back(s);
        return res;
    }