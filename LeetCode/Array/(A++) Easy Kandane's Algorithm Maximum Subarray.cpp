// https://leetcode.com/problems/maximum-subarray/discuss/1466615/c-kandanes-algorithm-simple-solution

// Logic: Kandane's Algorithm - Keep adding a[i] to the sum as long as sum>0, when it reaches below 0, make sum=0, store maximum sum in max variable and return it.

int maxSubArray(vector<int>& a) {
    int maxi = a[0], sum = 0;
    for(auto &g:a){
        sum += g;
        maxi = max(sum, maxi);
        sum = sum>0 ? sum : 0;
    }
    return maxi;
}