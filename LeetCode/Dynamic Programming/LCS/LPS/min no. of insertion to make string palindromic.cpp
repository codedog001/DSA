//Same result is for min. no of deletion to make string palindromic

Logic: Problem: Minimum no. insertion to make string palindromic.
E.g: Consider string => x: agbcba
Longest palindromic subsequence = LPS(x) = abcba
5 characters present are palindromic subsequence, len(x) = 6
6-5 =1 character doesn't have palindromic counterpart, so apply simple logic, only 1 char insertion 'g' will make whole string palindromic, and that's what we are doing in code.

Prerequisite: Longest Palindromic Subsequence
DP

int minInsertions(string a) {
     string b = a;
        reverse(b.begin(), b.end());
        int lps = lcs(a, b);
        int x = a.size();
        return x-lps;
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