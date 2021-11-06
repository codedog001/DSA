1. Memoization

    int climbStairsHelper(int n, vector<int>& t){
        if(n<=1) return 1;
        if(t[n] != -1) return t[n];
        else return t[n] = climbStairsHelper(n-1, t) + climbStairsHelper(n-2, t);
    }
    int climbStairs(int n) {
        if(n<=1) return 1;
        vector<int> t(n+1,-1);
        return climbStairsHelper(n,t);
    }

    
2. Tabulation (DP)

int climbStairs(int n) {
        int t[n+1];
        t[0] =1;
        t[1] = 1;
        for(int i=2; i<n+1; i++) t[i] = t[i-1] + t[i-2];
        return t[n];
    }