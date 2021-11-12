1. Recursive: (TLE)

	int longestCommonSubsequence(string text1, string text2) {
        return helper(text1, text2, text1.size(), text2.size());
    }
    
    int helper(string a, string b, int x, int y){
        if(x==0 || y==0) return 0;
        if(a[x-1] == b[y-1]) return 1 + helper(a, b, x-1, y-1);
        else return max(helper(a, b, x-1, y), helper(a, b, x, y-1));
    }
2. Memoized: (Recursive + Storage)
Remember, pass string with reference, otherwise you'll get TLE.

int longestCommonSubsequence(string a, string b) {
        int x = a.size(), y = b.size();
        int t[1001][1001];
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                t[i][j] = -1;
            }
        }
        return helper(a, b, x, y, t);
    }
    
    int helper(string& a, string& b, int x, int y, int t[][1001] ){
        //Base case
        if(x == 0 || y == 0) return 0;
        
        //If answer already exists return it.
        if(t[x][y] != -1) return t[x][y];
        
        //Else make recursive calls
        if(a[x-1] == b[y-1]){
            t[x][y] = 1 + helper(a, b, x-1, y-1, t);
            return t[x][y];
        } 
        else{
            t[x][y] = max(helper(a, b, x-1, y, t), helper(a, b, x, y-1, t));
            return t[x][y];
        } 
    }
3. DP

    int longestCommonSubsequence(string a, string b) {
        int x = a.size(), y = b.size();
        int t[x+1][y+1];
        
        //Initialization
        for(int i=0; i<x+1; i++) t[i][0] = 0;
        for(int j=0; j<y+1; j++) t[0][j] = 0;
        
        //LCS
        for(int i=1; i<x+1; i++){
            for(int j=1; j<y+1; j++){
                if(a[i-1] == b[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[x][y];
    }