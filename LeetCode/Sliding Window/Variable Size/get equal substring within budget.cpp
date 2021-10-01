int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0,maxLen=0;
        for(j=0;j<s.size();j++){
            maxCost -= abs(s[j] - t[j]);
            
            if(maxCost < 0){
                while(maxCost < 0) {
                    maxCost += abs(s[i]-t[i]);
                    i++;
                }
            }
            maxLen = max(j-i+1, maxLen);
        }
        return maxLen;
    
    }