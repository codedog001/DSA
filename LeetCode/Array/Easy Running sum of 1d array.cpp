//1. From the most upvoted solution
vector<int> runningSum(vector<int>& nums) {
    partial_sum(begin(nums), end(nums), begin(nums));
    return nums;
}

//2. Using for loop
vector<int> runningSum(vector<int>& a) {
       vector<int> res;
        if(a.empty()) return res;
        int sum=0;
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<=i; j++) sum += a[j];
            res.push_back(sum);
            sum=0;
        }
        return res;
    }