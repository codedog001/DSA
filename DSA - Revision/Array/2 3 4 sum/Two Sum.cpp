class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int newTarget = target - nums[i];
            if(m.find(newTarget) != m.end()) return {m[newTarget], i};
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};