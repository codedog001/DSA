//1. From the most upvoted solution
vector<int> runningSum(vector<int>& nums) {
    partial_sum(begin(nums), end(nums), begin(nums));
    return nums;
}

//2. Using a single for loop
vector<int> runningSum(vector<int>& a) {
        if(a.empty()) return a;

        for(int i=1; i<a.size(); i++){
            a[i] +=a[i-1];
        }
        return a;
    }