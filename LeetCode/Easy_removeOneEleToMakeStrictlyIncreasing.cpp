class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                count++;
            }
            if(count >1){
                return false;
            }
        }
        if(count <= 1){
            return true;
        }
        return false;
    }
};