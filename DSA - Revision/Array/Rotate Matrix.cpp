//Key: In transpose, the j loop runs till j < i only
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        //1. Transpose
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){ //Key
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //Reverse the rows
        for(auto &row:matrix){
            reverse(row.begin(), row.end());
        }
        
    }
};