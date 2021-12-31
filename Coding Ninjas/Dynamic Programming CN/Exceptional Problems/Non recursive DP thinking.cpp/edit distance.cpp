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


int editDistance(string s1, string s2) {
	// Write your code here
    int common =  longestCommonSubsequence(s1,s2);
    return max(s1.size(), s2.size()) - common;
}