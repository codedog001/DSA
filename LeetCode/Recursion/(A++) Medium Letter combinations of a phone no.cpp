    void rec(vector<string>& res, int index, vector<string> mapping, string current, string digits){
        if(digits.size() == index){
            res.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        
        for(int i=0; i<letters.size(); i++){
            string temp = current;
            current = current + letters[i];
            rec(res, index+1, mapping, current, digits);
            current = temp;
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        vector<string> mapping {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current = "";
        int index =0;
        rec(res,index,mapping,current, digits);
        return res;
    }