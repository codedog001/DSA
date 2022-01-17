// 1. Using prefix and suffix array: O(n) space -> Optimized further ahead in 2. 

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size(), maxLeft = 0, maxRight = 0, water=0;
        vector<int> left(n,0), right(n,0);
        
        for(int i=0; i<n; i++) {
            maxLeft = max(height[i], maxLeft);
            left[i] = maxLeft;
        }
        
        for(int i=n-1; i>=0; i--){
            maxRight = max(height[i], maxRight);
            right[i] = maxRight;
        } 
        
        for(int i=0; i<n; i++){
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};

// 2. Using two pointers: O(1) space

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int left = 0, right = n-1, maxLeft = 0, maxRight = 0, water = 0;
        while(left<right){
            if(height[left] <= height[right]){
                if(height[left] > maxLeft) maxLeft = height[left];
                else water += maxLeft - height[left];
                left++;
            }
            else{
                if(height[right] > maxRight) maxRight = height[right];
                else water += maxRight - height[right];
                right--;
            }
        }
        return water;
    }
};