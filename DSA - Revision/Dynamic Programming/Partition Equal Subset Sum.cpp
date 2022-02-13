class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        //Find sum of all elements of array
        int sum = 0, n= nums.size();
        
        for(auto& num: nums) sum += num;
        if(sum % 2 == 1) return false;
        else {
            int target = sum/2;
            dp.resize(target+1, vector<int>(n+1, -1));
            return checkIfTargetSumExists(nums, target, n-1);
        }
    }
    
    bool checkIfTargetSumExists(vector<int>& nums, int target, int index){
        if(index<0) return false;
        if(target == 0) return true;
        
        if(dp[target][index] != -1) return dp[target][index];
        if(nums[index] <= target){
            //Choice to include element or skip it.
            return dp[target][index] = checkIfTargetSumExists(nums, target-nums[index], index-1) || checkIfTargetSumExists(nums, target, index-1);
        }
        else return dp[target][index] = checkIfTargetSumExists(nums, target, index-1);
    }
};