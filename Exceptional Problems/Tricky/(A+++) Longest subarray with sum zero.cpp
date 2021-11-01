#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int, int> m;
    m[0] = -1;
    int len = 0, sum=0, maxLen = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(m.find(sum) != m.end()){
            len = abs(m[sum] - i);
            maxLen = max(maxLen, len);
        }
        else m[sum] = i;
        
    }
    return maxLen;
    
}