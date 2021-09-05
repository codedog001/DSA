class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string p = normalise(pattern);
        vector<string> res;
        for(auto &str : words){
            if(normalise(str) == p){
                res.push_back(str);
            }
        }
        return res;
    }
    
    string normalise(string w){
        unordered_map<char,char> mp;
        char c = 'a';
        
        for(auto &ch : w){
            if(!mp.count(ch)){
                mp[ch] = c++;
            }
        }
        
        for(auto & ch : w){
            ch = mp[ch];
        }
        
        return w;
    }
    
};