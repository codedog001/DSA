void rotate(vector<vector<int>>& a) {
        /*
        Steps - 
        1. Transpose given matrix  -> Row becomes column, column becomes row.
        2. Reverse all the rows of given matrix
        */
        
        //1. Transpose
        int n= a.size();
        for(int i=0; i< n; i++){
            for(int j=0; j<i; j++){
                swap(a[i][j],a[j][i]);
            }
        }
        //2. Reverse
        for(int i=0; i<n; i++){
            reverse(a[i].begin(), a[i].end());
        }
        return;
    }