//Sort 0 1 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size(), low = 0, high = n-1, mid = 0;
        
        while(mid <= high){
            switch(nums[mid]){
                case 0:{
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                    break;
                }
                case 1:{
                    mid++;
                    break;
                }
                case 2:{
                    swap(nums[mid], nums[high]);
                    high--;
                    break;
                }
            }
        }
    }
};