int maxFreq(string a, int maxLetters, int minSize, int maxSize) {
        int i=0,j=0, count=0;
        unordered_map<char,int> m;
        unordered_map<string, int> m2;
        int maxRepeating = 0;
        
        for(j=0; j<a.size(); j++){
            m[a[j]]++;
            if(m[a[j]] == 1) count++;
            
            if(j-i+1>minSize){
                m[a[i]]--;
                if(m[a[i]] == 0) count--;
                i++;
            }
            
            if(count <= maxLetters && j-i+1 >= minSize){
                string sub = a.substr(i,minSize);
                m2[sub]++;
                maxRepeating = max(maxRepeating, m2[sub]);
            }
        }
        return maxRepeating;
    }