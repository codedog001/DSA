class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        //If gcd is 1, then only it is possible.
        int gcd = nums[0];
        for(auto &n: nums){
            gcd = __gcd(n,gcd);
        }
        return gcd == 1;
    }
};