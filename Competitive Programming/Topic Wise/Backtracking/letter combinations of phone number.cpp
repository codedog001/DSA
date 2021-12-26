class Solution {
public:
    vector<string> res, mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string combination = "";
        helper(digits, 0, combination);
        return res;
    }
    
    void helper(string& digits, int index, string& comb){
        if(index == digits.size()){
            res.push_back(comb);
            return;
        }
        
        for(auto c: mapping[digits[index] - '0']){
            comb += c;
            helper(digits, index+1, comb);
            comb.pop_back();
        }
    }
};