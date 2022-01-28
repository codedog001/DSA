// Logic: Find the longest length of increasing sequence at each index i,j and store it in dp[i][j], later we check if dp[i][j] already contains a value other than 0, then it is the lenght longest increasing subsequence starting from that index, and redundant calls are avoided.

class Solution {
public:
    int n = 0, m=0;
    int b[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    vector<vector<int>> dp;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(); 
        m = matrix[0].size(); 
        int res = 0;
        
        dp.resize(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res = max(dfs(i,j,matrix), res);
            }
        }
        return res;
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix){
        if(dp[i][j] != 0) return dp[i][j];
        int count = 1;
        for(int k=0; k<4; k++){
            int newI = i+b[k][0];
            int newJ = j+b[k][1];
            
            if(isValid(newI, newJ) && matrix[newI][newJ] > matrix[i][j]){
                count = max(1+ dfs(newI, newJ, matrix), count);
            }
        }
        return dp[i][j] = count;
    }
    
    bool isValid(int newI, int newJ){
        if(newI >=0 && newJ >= 0 && newI < n && newJ < m) return true;
        return false;
    }
};