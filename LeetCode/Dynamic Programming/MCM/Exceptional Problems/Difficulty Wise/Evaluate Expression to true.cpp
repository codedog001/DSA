1. Memoized (Map)
    unordered_map<string, int> m;
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
        string key = to_string(i) + to_string(j) + to_string(isTrue); //This is the best part and the smartest code.
        if(m.find(key) != m.end()) return m[key];
        
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
        
        return m[key] = ans%1003;
    }

2. Memoized (3D Matrix)

int t[201][201][2]; // 2 because isTrue can take only 2 values - True or false.
    int countWays(int N, string S){
        // code here
        int i=0, j= S.size()-1, isTrue = true;
        memset(t, -1, sizeof(t));
        return solve(S, i, j, isTrue);
    }
    
    int solve(string s, int i, int j, bool isTrue){
        //Base Case
        if(i > j) return t[i][j][isTrue] = 0;
        if(i==j){
            if(isTrue == true) {
                if(s[i] == 'T') return t[i][j][isTrue] = 1;
                else return t[i][j][isTrue] = 0;
            }
            else{
                if(s[i] == 'F') return 1;
                else return t[i][j][isTrue] = 0;
            }
        }
        if(t[i][j][isTrue] != -1) return t[i][j][isTrue];
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
        return t[i][j][isTrue] = ans%1003;
    }

3. Recursive (TLE)
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