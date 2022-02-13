class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        subsets(nums, 0, subset, res);
        return res;
    }
    
private:
    void subsets(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);
        for (int j = i; j < nums.size(); j++) {
            subset.push_back(nums[j]);
            subsets(nums, j + 1, subset, res);
            subset.pop_back();
        }
    }
};