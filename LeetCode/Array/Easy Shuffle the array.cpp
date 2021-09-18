    vector<int> shuffle(vector<int> nums, int val) {
        // nums = [2,5,1,3,4,7], n=3
        
        for(int i = 0; i < val; i++){
            nums[i] += nums[val + i] * 10000;
        }
        
        //After 1st loop: [30002,40005,70001,3,4,7]
       
        
        for(int i = val - 1; i >= 0; i--){
            //i starts at i=2
            
            nums[2 * i + 1] = nums[i] / 10000;
            //nums[5] = nums[2]/10000 = 70001/10000 = 7
            
            nums[2 * i] = nums[i] % 10000;
            //nums[4] = nums[2]/10000 = 70001 % 10000 = 1
        }
        return nums;
    }