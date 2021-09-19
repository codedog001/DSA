    int numIdenticalPairs(vector<int>& nums) {
        unordered_multiset<int> m;
        int counter = 0;
        for(int i=0; i<nums.size(); i++){
            if(m.count(nums[i])){ 
                counter += m.count(nums[i]);
            }
            m.insert(nums[i]);
        }
        return counter;
    }