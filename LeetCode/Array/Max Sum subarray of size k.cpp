    int maximumSumSubarray(int k, vector<int> &a , int N){
        // code here 
        int i=0,j=0,sum=0,mxSum=0;
        while(j<a.size()){
            //1. Calculate sum 
            sum += a[j];
            
            //2. Until window size has not reached k, keep increasing j
            if(j-i+1 < k) j++;
            
            //3. When window size reaches k
            else if(j-i+1 == k){
                //sum has the sum of elements of window size k. So update mxSum.
                mxSum = max(mxSum, sum);
                
                //4. Now maintain window size - subtract a[i] from sum, and move i and j one element ahead.
                sum -= a[i];
                i++;
                j++;
            }
        }
        return mxSum;
    }