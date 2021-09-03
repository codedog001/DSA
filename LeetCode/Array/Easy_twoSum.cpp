class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            int numToFind = target - nums[i];
            
            //Element is found in hashmap
            if(hash.find(numToFind) != hash.end()){
                res.push_back(hash[numToFind]);
                res.push_back(i);
                return res;
            }
            
            hash[nums[i]] = i;
        }
        return res;
    }
    
};