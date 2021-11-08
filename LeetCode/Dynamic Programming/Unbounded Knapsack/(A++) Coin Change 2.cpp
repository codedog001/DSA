Why Knapsack?
We have choice among which coin to select & optimal (i.e. maximum/minimum, maximum in this problem) is asked so it is a knapsack problem.

Which Knapsack?
Infinite no. of coins -> Unbounded.

Approach: Recursive solution -> Memoize it -> DP (Remove overhead due to recursion)

Code:
1. Recursive: (TLE)

if(amount == 0) return 1;
        if(coins.size() == 0) return 0;
        int n= coins.size();
        return helper(coins, amount, n);
    }
    
    int helper(vector<int>& wt, int sum, int n){
        if(sum == 0) return 1;
        if(n <= 0) return 0;
        
        if(wt[n-1] <= sum){
            return helper(wt, sum-wt[n-1], n) + helper(wt, sum, n-1);
        }else{
            return helper(wt, sum, n-1);
        }
    }
2. Memoized: (Recursive + Storage)

    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(coins.size() == 0) return 0;
        int n= coins.size();
        vector<vector<int>>t(n+1, vector<int>(amount+1, -1));
        return helper(coins, amount, n, t);
    }
    
    int helper(vector<int>& wt, int sum, int n,  vector<vector<int>>& t){
        if(sum == 0) return 1;
        if(n <= 0) return 0;
        
        //Check if answer exists
        if(t[n][sum] != -1) return t[n][sum];
        
        if(wt[n-1] <= sum){
            t[n][sum] = helper(wt, sum-wt[n-1], n, t) + helper(wt, sum, n-1, t);
            return t[n][sum];
        }else{
            t[n][sum] = helper(wt, sum, n-1, t);
            return t[n][sum];
        }
    }
3. DP: (Stack space taken by recursion is removed)

    int change(int sum, vector<int>& coins) {
        if(sum == 0) return 1;
        if(coins.size() == 0) return 0;
        
        int n= coins.size();
        int t[n+1][sum+1];
        
        //Initialization
        for(int i=0; i<sum+1; i++) t[0][i] = 0;
        for(int j=1; j<n+1; j++) t[j][0] = 1;
        
        //Unbounded Knapsack
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1] <= j){
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }