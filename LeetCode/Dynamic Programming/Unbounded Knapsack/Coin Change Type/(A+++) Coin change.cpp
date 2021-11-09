Why Knapsack?
We have choice among which coin to select & optimal (i.e. maximum/minimum, minimum coins in this problem) is asked so it is a knapsack problem.

Which Knapsack?
Infinite no. of coins -> Unbounded.

Approach: Recursive solution -> Memoize it -> DP (Remove overhead due to recursion)

Code:
1. Recursive: (TLE)

int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        int res = helper(coins, n, sum);
        return (res==INT_MAX || res == INT_MAX-1) ? -1 : res;
    }
    
    int helper(vector<int>& coins, int n, int sum){
	//why INT_MAX-1 => Because later we are adding 1 while returning the value, so if we return INT_MAX here, doing INT_MAX+1 will cross the range of integer.
        if(n<=0) return INT_MAX-1;
        if(sum == 0) return 0;
        
		//Unbounded Knapsack Code
        if(coins[n-1] <= sum) {
            return min(1 + helper(coins, n, sum-coins[n-1]), helper(coins, n-1, sum));
        }
        else return helper(coins, n-1, sum);
    }
2. Memoized: (Recursive + Storage)

    int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
        int res = helper(coins, n, sum, t);
        
        return (res==INT_MAX || res == INT_MAX-1) ? -1 : res;
    }
    
    int helper(vector<int>& coins, int n, int sum, vector<vector<int>>& t){
        if(n<=0) return INT_MAX-1;
        if(sum == 0) return 0;
        
        if(t[n][sum] != -1) return t[n][sum];
        
		//Unbounded Knapsack Code
        if(coins[n-1] <= sum) {
            t[n][sum] = min(1 + helper(coins, n, sum-coins[n-1], t), helper(coins, n-1, sum, t));
            return t[n][sum];
        }
        else{
            t[n][sum] = helper(coins, n-1, sum, t);
            return t[n][sum];
        }
    }
    
3. DP:

int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        int t[n+1][sum+1];
        
        //Initialization
        for(int i=0; i<sum+1; i++) t[0][i] = INT_MAX-1;
        for(int j=1; j<n+1; j++) t[j][0] = 0;
        
        //Unbounded Knapsack
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1] <= j){
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return (t[n][sum] == INT_MAX || t[n][sum] == INT_MAX-1) ? -1 : t[n][sum];
    }