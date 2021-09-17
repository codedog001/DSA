//Apply binary search on the given matrix, main part to think of is calculating the index using mid - matrix[mid/col][mid%col]
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int col = a[0].size(), row = a.size();
        
        if(a.empty()) return false;
        
        int low = 0, high = (col*row) -1;
        
        while(low<=high){
            int mid = (high+(low-high)/2);
            cout<< "MID: " << mid << endl;
            cout << "checking index: i: " << mid/col << " j: " << mid%col << endl;
            if(a[mid/col][mid%col] == target) return true;
            if(a[mid/col][mid%col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
        
    }