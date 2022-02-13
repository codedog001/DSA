class Solution {
public:
    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(0, 0, grid);
    }
    
    int helper(int i, int j, vector<vector<int>>& grid){
        if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
        if(i >= grid.size() || j >= grid[0].size()) return 1000000;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = helper(i+1, j, grid);
        int right = helper(i, j+1, grid);
        
        return dp[i][j] = grid[i][j] + min(down, right);
    }
};