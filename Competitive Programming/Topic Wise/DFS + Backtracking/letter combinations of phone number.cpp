//DFS + Backtracking

class Solution {
public:
    vector<string> res, mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string combination = "";
        dfs(digits, 0, combination);
        return res;
    }
    
    void dfs(string& digits, int index, string& comb){
        if(index == digits.size()){
            res.push_back(comb);
            return;
        }
        
        for(auto c: mapping[digits[index] - '0']){
            comb += c;
            dfs(digits, index+1, comb);
            comb.pop_back();
        }
    }
};