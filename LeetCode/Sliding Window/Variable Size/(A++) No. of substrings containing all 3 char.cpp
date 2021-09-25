int numberOfSubstrings(string a) {
        int i=0,j=0,count=0,resCount=0;
        unordered_map<char,int> m;
        
        string s = "abc";
        for(auto& c:s) m[c]++;
        count = m.size();
        
        while(j<a.size()){
            //1. Calculation
            m[a[j]]--;
            if(m[a[j]] == 0) count--;
            
            if(count > 0) j++;
            else if(count == 0){
                // 1. Get answer from calculation
                while(count == 0){
                    m[a[i]]++;
                    if(m[a[i]] == 1) count++;
                    resCount+=a.size()-j;
                    i++;
                }
                j++;
            }
        }
        return resCount;
    }