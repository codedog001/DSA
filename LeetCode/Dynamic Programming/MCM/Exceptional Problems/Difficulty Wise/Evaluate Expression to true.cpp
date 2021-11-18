int countWays(int N, string S){
        // code here
        int i=0, j= S.size()-1, isTrue = true;
        return solve(S, i, j, isTrue);
    }
    
    int solve(string s, int i, int j, bool isTrue){
        //Base Case
        if(i > j) return 0;
        if(i==j){
            if(isTrue == true) {
                if(s[i] == 'T') return 1;
                else return 0;
            }
            else{
                if(s[i] == 'F') return 1;
                else return 0;
            }
        }
        
        int ans = 0;
        //Move k
        
        for(int k=i+1; k<=j-1; k+=2){
            int lt = solve(s, i, k-1, true);
            int rt = solve(s, k+1, j, true);
            int lf = solve(s, i, k-1, false);
            int rf = solve(s, k+1, j, false);
            
            if(s[k] == '&'){
                if(isTrue == true) ans = ans + (lt * rt);
                else ans = ans + (lf * rt) + (lt * rf) + (lf * rf);
                
            }
            else if(s[k] == '|'){
                if(isTrue == true) ans = ans + (lf * rt) + (lt * rf) + (lt * rt);
                else ans = ans + (lf * rf);
            }
            else if(s[k] == '^'){
                if(isTrue == true) ans = ans + (lf * rt) + (lt * rf);
                else ans = ans + (lt * rt) + (lf * rf);
            }
        }
        return ans;
    }