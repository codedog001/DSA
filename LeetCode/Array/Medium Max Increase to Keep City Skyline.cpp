class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxEleRow(grid.size(),0);
        vector<int> maxEleCol(grid.size(),0);
        int maxEle = 0;
        
        //Max element of row and column.
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                maxEleRow[i] = max(maxEleRow[i], grid[i][j]);
                maxEleCol[j] = max(maxEleCol[j], grid[i][j]);
            }
        }
        
        int result = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                    result += min(maxEleRow[i], maxEleCol[j]) - grid[i][j];
                
            }
        }
        
        return result;
    }
};