class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> res;
        if(n<3) return res;
        
        sort(nums.begin(), nums.end());
        int i=0, j=0, k=n-1;
        
        while(i<n){
            int target = -1 * nums[i];
            j=i+1;
            k=n-1;
            
            while(j<k){
                if(nums[j] + nums[k] == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(nums[j] + nums[k] < target) j++;
                else k--;
            }
            
            i++;
            while(i<n && nums[i] == nums[i-1]) i++;
            if(i<n && nums[i] > 0) break;
        }
        
        return res;
    }
};