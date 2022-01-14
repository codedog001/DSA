class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), j = matrix[0].size()-1, i=0;
        while(j>=0 && i<n){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] < target) i++;
            else if(matrix[i][j] > target) j--;
        }
        
        return false;
    }
};