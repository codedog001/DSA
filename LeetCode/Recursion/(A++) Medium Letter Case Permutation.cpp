    void rec(string s, string op, vector<string>& res, int index){
        if(index == s.size()){
            res.push_back(op);
            return;
        }
        if(isdigit(s[index])){
            string op3 = op;
            op3.push_back(s[index]);
            
            rec(s,op3,res,index+1);
        }
        
        if(isalpha(s[index])) {
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(s[index]));
            op2.push_back(toupper(s[index]));
            
            rec(s,op1,res,index+1);
            rec(s,op2,res,index+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        if(s.empty()) return res;
        string op = "";
        rec(s,op,res,0);
        return res;
    }