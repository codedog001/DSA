class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxValue(n), minValue(n);
        
        maxValue[0] = minValue[0] = nums[0];
        
        int result = nums[0];
        
        for(int i=1; i<n; i++){
            maxValue[i] = max({maxValue[i-1] * nums[i], minValue[i-1] * nums[i], nums[i]});
            minValue[i] = min({minValue[i-1] * nums[i], maxValue[i-1] * nums[i], nums[i]});
            result = max(maxValue[i], result);
        }

        return result;
    }
};