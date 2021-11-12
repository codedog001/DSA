Logic: Explained as comments in recursive code. Also, remember to pass string by reference in memoized solution to avoid TLE.
T.C of recursive and memoized solution: O(NM), where N, M is the length of s and p.

1. Recursive

    bool isMatch(string s, string p) {
        int i=0, j=0;
        
        //i is pointer on s
        //j is pointer on p
        return fun(s,p,i,j);
    }
    
    bool fun(string& s, string& p, int i, int j){
        //1. Base case
        //a. String p has ended - s must have ended for a match between them.
        if(j==p.size()) return i == s.size();
        
        //b. String s has ended - p[j] could only be '*' or multiple '*' for a match.
        if(i==s.size()) return (p[j] == '*' && fun(s,p,i,j+1));
        
        //2. If none of them has ended and p[j] is '*', nothing can be said before comparing rest of the strings, both of them.
        if(p[j] == '*') return fun(s,p,i+1,j) || fun(s,p,i,j+1);
        
        //3. Else, when p[j] = '?' or a character - If it is a character it must be same as s[i]
        else{
            bool sameChar = i<s.size() && (p[j] == s[i] || p[j] == '?');
            return (sameChar && fun(s,p,i+1,j+1));
        }
    }
2. Memoized: (Recursion + Storage)

	bool isMatch(string s, string p) {
        int i=0, j=0;
        
        //i is pointer on s
        //j is pointer on p
        int x = s.size(), y = p.size();
        int t[2002][2002];
        
        for(int k=0; k<x+1; k++){
            for(int m=0; m<y+1; m++){
                t[k][m] = -1;
            }
        }
        return fun(s,p,i,j, t);
    }
    
    bool fun(string& s, string& p, int i, int j, int t[][2002]){
        //1. Base case
        //a. String p has ended - s must have ended for a match between them.
        if(j==p.size()) return i == s.size();
        
		//Check if result exists
        if(t[i][j] != -1) return t[i][j];
		
        //b. String s has ended - p[j] could only be '*' or multiple '*' for a match.
        if(i==s.size()) return (p[j] == '*' && fun(s,p,i,j+1, t));
        
        
        //2. If none of them has ended and p[j] is '*', nothing can be said before comparing rest of the strings, both of them.
        if(p[j] == '*') {
            t[i][j] = fun(s,p,i+1,j,t) || fun(s,p,i,j+1, t);
            return t[i][j];
        }
        
        //3. Else, when p[j] = '?' or a character - If it is a character it must be same as s[i]
        else{
            bool sameChar = i<s.size() && (p[j] == s[i] || p[j] == '?');
            t[i][j] = (sameChar && fun(s,p,i+1,j+1, t));
            return t[i][j];
        }
    }
3. DP:

    bool isMatch(string& s, string& p) {
        if(p.size()==0) return s.size() == 0;
        
        int x = s.size(), y = p.size();
        vector<vector<int>> t(x+1, vector<int>(y+1,0));
        
        t[0][0] = 1;
        
        for(int i=1; i<=p.size(); i++){
            if(p[i-1] == '*') t[0][i] = 1;
            else break;
        }
        
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=p.size(); j++){
                if(p[j-1] == '*')  t[i][j] = t[i-1][j] || t[i][j-1];
                else if(p[j-1] == '?' || p[j-1] == s[i-1]) {
                    t[i][j] = t[i-1][j-1];
                }
            }
        }
        return t[x][y];
    }