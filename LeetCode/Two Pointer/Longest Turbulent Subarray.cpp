    int maxTurbulenceSize(vector<int>& a) {
        if(a.size() == 1) return 1;
        int maxLen=1, j=0;
        int inc=1, dec =1;

        
        for(j=0; j<a.size()-1; j++){
            if(a[j] > a[j+1]){
                inc = dec+1;
                dec =  1;
            }else if(a[j] < a[j+1]){
                dec = inc + 1;
                inc = 1;
            }else{
                dec=1;
                inc=1;
            }
            maxLen = max(maxLen, max(inc, dec));
            
        }
        return maxLen;
    }