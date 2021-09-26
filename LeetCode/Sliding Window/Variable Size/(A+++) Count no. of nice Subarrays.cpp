Exactly = atMostK(k) - atMostK(k-1)

int atMostK(vector<int>& a, int k) {
        int i=0,count = 0,res =0;
        for(int j=0;j<a.size();j++){
            if(a[j]%2==1) count++;
            if(count > k){
                while(count>k){
                    if(a[i]%2==1) count--;
                    i++;
                }
            }
            res += j-i+1;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& a, int k) {
        return atMostK(a,k) - atMostK(a,k-1);
    }