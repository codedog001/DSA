Logic: Longest palindromic subsequence (LPS) is a variant of longest common subsequence (LCS). All we need to do is find the LCS between given string a, and reverse of a.

For E.g: string a: "agbcba", string b (reverse of a): abcbga
LCS(a,b): abcbga

int longestPalindromeSubseq(string a) {
        string b = a;
        reverse(b.begin(), b.end());
        int lps = lcs(a,b);
        return lps;
    }
    
    int lcs(string a, string b){
        int x = a.size(), y = b.size();
        int t[x+1][y+1];
        
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                if(i==0 || j==0) t[i][j] = 0;
                else{
                    if(a[i-1] == b[j-1]) t[i][j] = 1 + t[i-1][j-1];
                    else t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[x][y];
    }