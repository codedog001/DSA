//1. When modifying given input is allowed use swap sort

vector<int> repeatedNumber(vector<int> &nums) {
        int i=0, n = nums.size(); 
        vector<int> res(2,0);
        while(i<n){
            if(nums[i] != nums[nums[i]-1]) swap(nums[nums[i]-1], nums[i]);
            
            else i++;
        }
        for(i=0; i<n; i++){
            if(nums[i] != i+1) {
                res[0] = nums[i]; //Duplicate 
                res[1] = i+1; //Missing
            } 
        }
        return len;
}

//2. When modification is not allowed use slow and fast pointers