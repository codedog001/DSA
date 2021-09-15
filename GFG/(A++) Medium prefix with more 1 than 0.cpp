    void rec(int n,vector<string> & res, int one, int zero, string op){
        if(n==0){
            res.push_back(op);
            return;
        }
       
        string op1 = op;
        op1.push_back('1');
        rec(n-1,res,one+1,zero,op1);
        
        if(one>zero){
            string op2 = op;
            op2.push_back('0');
            rec(n-1,res,one,zero+1,op2);
        }
        return;
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> res;
	    string op = "";
	    rec(n,res,0,0,op);
	    return res;
	}