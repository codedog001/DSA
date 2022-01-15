class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        if(n < 4) return {};
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        int i=0, j=0, k=0, l=0;
        
        while(i<n-3){
            int a = nums[i];
            j=i+1;
            while(j<n-2){
                int b = nums[j];
                int newTarget = target - (a + b);
                l=j+1;
                k=n-1;
                
                while(l<k){
                    int curSum = nums[l] + nums[k];
                    if(curSum == newTarget){
                        res.push_back({a, b, nums[l], nums[k]});
                        l++;
                        k--;
                        
                        while(l<k && nums[l] == nums[l-1]) l++;
                        while(l<k && nums[k] == nums[k+1]) k--;
                    }
                    
                    else if(curSum < newTarget) l++;
                    else k--;
                }
                j++;
                while(j<n && nums[j] == nums[j-1]) j++;
            }
            
            i++;
            while(i<n && nums[i] == nums[i-1]) i++;
        }
        
        return res;
        
    }
};