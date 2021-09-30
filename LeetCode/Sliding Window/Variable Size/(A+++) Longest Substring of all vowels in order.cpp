int longestBeautifulSubstring(string a) {
        int i=0,j=0,len=1,count=1,maxLen=0;
        for(int i=1; i< a.size(); i++){
           if(a[i] == a[i-1]){
                len++;
            }
            else if(a[i] > a[i-1]){
                len++;
                count++;
            }else if(a[i]<a[i-1]){
                len=1;
                count=1;
            }
            
            if(count == 5) maxLen = max(len, maxLen);
        }
        return maxLen;
    }