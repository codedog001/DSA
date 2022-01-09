class Solution {
public:
    
    void setZeroes(vector<vector<int>>& a) {
        int rows = a.size(), cols = a[0].size();
        bool col0 = false, row0 = false;
        
        for(int i=0; i<cols; i++) if(a[0][i] == 0) row0 = true;
        for(int i=0; i<rows; i++) if(a[i][0] == 0) col0 = true;
        
        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(a[i][j] == 0){
                    a[0][j] = 0;
                    a[i][0] = 0;
                }
            }
        }
        
        //Set zeros in matrix
        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(a[i][0] == 0 || a[0][j] == 0) a[i][j] = 0;
            }
        }
        if(row0){
            for(int i=0; i<cols; i++) a[0][i] = 0;
        }
        if(col0){
            for(int i=0; i<rows; i++) a[i][0] = 0;
        }
    }
};