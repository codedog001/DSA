class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(amount+1, vector<int>(n+1, -1));
        int result = helper(coins, amount, n-1);
        return result == 9999999 ? -1 : result;
    }
    
    int helper(vector<int>& coins, int amount, int index){
        if(index < 0) return 9999999;
        if(amount <= 0) return 0;
        
        if(dp[amount][index] != -1) return dp[amount][index];
        if(coins[index] <= amount){
            //Choice: Select the coin or skip it
            return dp[amount][index] = min(1 + helper(coins, amount - coins[index], index), helper(coins, amount, index-1));
        }
		//No choice
        else return dp[amount][index] = helper(coins, amount, index-1);
    }
};