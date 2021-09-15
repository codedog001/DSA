    void rec(vector<string>& res, string str, int open, int close){
        if(open==0 && close==0){
            res.push_back(str);
            return;
        }
   
        //Choice of closing bracket is only available when there is an open bracket available
        if(close>open){
            string s2 = str;
            s2.push_back(')');
            rec(res,s2,open,close-1);
        }
        
        //Choice of open bracket is always available as long open > 0
        if(open!=0){
            string s1 = str;
            s1.push_back('(');
            rec(res,s1, open-1,close);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open=n, close=n;
        vector<string> res;
        string str = "";
        rec(res,str,open,close);
        return res;
    }