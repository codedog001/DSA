int longestKSubstr(string a, int k) {
    // your code here //
    unordered_map<char,int> m;
    int i=0,j=0,maxLen=-1;
    
    while(j<a.size()){
        //1. Calculation
        m[a[j]]++;
        
        if(m.size()<k) j++;
        
        else if(m.size() == k){
            int numOfUniqueChar = j-i+1;
            maxLen = (maxLen, numOfUniqueChar);
            j++;
        }
        
        else if(m.size() >k){
            while(m.size() > k){
                m[a[i]]--;
                if(m[a[i]] == 0) m.erase(a[i]);
                i++;
            }
            j++;
        }
    }

    return maxLen;
    }
