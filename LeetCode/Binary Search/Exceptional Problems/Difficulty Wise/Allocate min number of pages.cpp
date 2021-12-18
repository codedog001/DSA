//Leetcode Version: https://leetcode.com/problems/split-array-largest-sum/

class Solution {
// This problem is leetcode equivalent of allocate minimum no. of pages
public:
    bool isValid(vector<int>& a, int mid, int m){
        int s = 1, n = a.size(), sum=0;
        for(int i=0; i<n; i++){
            sum += a[i];
            if(sum > mid) {
                s++;
                sum = a[i];
            }
            if(s>m) return false;
        }
        return true;
    }
    
    int splitArray(vector<int>& a, int m) {
        int n= a.size();
        if(n < m) return -1;
        
        int start=0, end=0, res = 0;
        for(auto &c:a){
            start = max(start, c);
            end += c;
        }

        while(start <= end){
            int mid = start + (end-start)/2;
            if(isValid(a,mid,m)){
                res = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return res;
    }
};