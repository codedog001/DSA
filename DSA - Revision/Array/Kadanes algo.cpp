//O(n) Using Kadane's algorithm, also store index of start and end index
class Solution {
public:
    int maxSubArray(vector<int>& a, vector<int>& storeStartEnd) {
        int curSum = 0, maxSum = INT_MIN, n = a.size(), start = 0, end = 0;
        
        for(int i=0; i<n; i++){
            curSum += a[i];
            if(curSum > maxSum){
                end = i;
                storeStartEnd[0] = start;
                storeStartEnd[1] = end;
                maxSum = curSum;
            }
            if(curSum < 0) {
                curSum = 0;
                start = i+1;
            }
        }
        
        return maxSum;
    }
};


//O(n^2) solution
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int curSum = 0, maxSum = INT_MIN, n = a.size();
        cout << "size: " << n << endl;
        for(int i=0; i<n; i++){
            curSum = 0;
            for(int j=i; j<n; j++){
                curSum += a[j];
                if(curSum > maxSum){
                    maxSum = curSum;
                }
            }
        }
        return maxSum;
    }
};