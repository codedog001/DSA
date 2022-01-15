class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        int arraySize = nums.size(), i=0;
        if(arraySize == 0) return 0;
        
        for(auto& num:nums) m[num] = false;
        int maxLen = 1;
        
        while(i<arraySize){
            int ele = nums[i];
            if(m[ele] == false){
                int inc = ele+1, curLen = 0;

                while(m.find(inc) != m.end()){
                    m[inc] = true;
                    curLen++;
                    inc++;
                }

                int dec = ele-1;
                while(m.find(dec) != m.end()){
                    m[dec] = true;
                    curLen++;
                    dec--;
                }

                maxLen = max(curLen+1, maxLen);
            }
            i++;
        }
        
        return maxLen;
    }
};