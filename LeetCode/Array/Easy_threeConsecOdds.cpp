class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        vector<int> index;
        int count=0;
        for(int i=0;i<arr.size() && count<3;i++){
            count = arr[i]%2 == 0 ? 0 : count+1;
        }
        return count == 3;
    }
};