    int maxScore(vector<int>& a, int k) {
       //This problem translates to find smallest subarray sum of length (cards-k)
        int i=0,j=0,sum=0, minSum=INT_MAX;
        int targetLen = a.size() - k;
        
        
        //Total sum of given array
        int netSum = accumulate(a.begin(), a.end(),0);
        if(k== a.size()) return netSum;
        
        while(j<a.size()){
            sum += a[j];
            
            if(j-i+1<targetLen) j++;
            else if(j-i+1 == targetLen){
                minSum = min(sum,minSum);
                sum -= a[i];
                i++;
                j++;
            }
        }
        return netSum - minSum;
    }