int numOfSubarrays(vector<int>& a, int k, int t) {
        int i=0,j=0,sum=0, count = 0;
        while(j<a.size()){
            //1. Calculation
            sum+=a[j];
            
            //2. Move j
            if(j-i+1 < k) j++;
            
            //3. When window size is reached
            else if(j-i+1 == k){
                //i. Get ans from calculation
                int avg = sum/k;
                if(avg>=t) count++;
                
                //Remove i from calculation
                sum -= a[i];
                
                //Side Window
                j++;
                i++;
            }
        }
        return count;
    }