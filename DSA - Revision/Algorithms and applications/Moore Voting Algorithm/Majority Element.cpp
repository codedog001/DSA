class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Using moore's voting algorithm
        int count = 0, candidate = 0;
        
        for(auto& ele: nums){
            if(count == 0) candidate = ele;
            if(ele == candidate) count += 1;
            else count -= 1;
        }
        return candidate;
    }
};