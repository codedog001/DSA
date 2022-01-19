//1. When modifying given input is allowed use swap sort

vector<int> repeatedNumber(vector<int> &nums) {
        int i=0, n = nums.size(); 
        vector<int> res(2,0);
        while(i<n){
            if(nums[i] != nums[nums[i]-1]) swap(nums[nums[i]-1], nums[i]);
            
            else i++;
        }
        for(i=0; i<n; i++){
            if(nums[i] != i+1) {
                res[0] = nums[i]; //Duplicate 
                res[1] = i+1; //Missing
            } 
        }
        return len;
}

//2. When modification is not allowed use Floyd's Tortoise and Hare (Cycle Detection)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        fast = nums[0];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        } 
        
        return slow;
    }
};