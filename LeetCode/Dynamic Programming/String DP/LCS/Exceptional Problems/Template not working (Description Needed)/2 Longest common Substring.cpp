//What's not working:
1. Memoized version is taking a 3d array while DP version is working in 2d array.
2. It has 3 changing factors - understandable, x,y and count (i.e. result), but why not
working for memoized and working for DP code?

3. Memoized - NOt working for 2d array, 3d array very large giving segementation fault

2. Memoized Code => Error
    int helper(string X, string Y, int m, int n,int lcsCount, int ***dp){
        if (m <= 0 || n <= 0)
			return lcsCount;

		if (dp[m][n][lcsCount] != -1)
			return dp[m][n][lcsCount];

		int lcsCount1=lcsCount;
		if (X[m - 1] == Y[n - 1])
			lcsCount1 = helper(X, Y, m - 1, n - 1, lcsCount + 1, dp);

		int lcsCount2 = helper(X, Y, m, n - 1, 0, dp);
		int lcsCount3 = helper(X, Y, m - 1, n, 0, dp);

		return dp[m][n][lcsCount] = max(lcsCount1, max(lcsCount2, lcsCount3));
    }

    
3. DP Code
int longestCommonSubstr(string a, string b, int x, int y)
    {
        int res = 0;
        int t[x+1][y+1];
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                if(i==0 || j== 0) t[i][j] = 0;
                else{
                    if(a[i-1] == b[j-1]){
                        t[i][j] = 1+ t[i-1][j-1];
                        
                        //Store length of largest substring
                        res = max(t[i][j], res);
                    }
                    else t[i][j] = 0;
                }
            }
        }
        return res;
    }
