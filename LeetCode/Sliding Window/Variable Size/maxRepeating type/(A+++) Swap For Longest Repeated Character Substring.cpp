// Similar questions in same folder.

// Note: If you haven't yet solved Leetcode 424. Longest Repeating Character Replacement, I will highly encourage you to do that first, it is the modification of very same question, and the intuition behind the solution used in this problem can be found here: Click Here

// Based on that intuition here is the code with k=1

    int maxRepOpt1(string a) {
        int i=0,j=0,count=0,maxLen=0,k=1,maxRepeating=0;
        unordered_map<char,int> m;
        char maxRepeatingChar;
        
        for(j=0; j<a.size(); j++){
            m[a[j]]++;
            if(m[a[j]] >= maxRepeating){
                maxRepeating = max(maxRepeating, m[a[j]]);
                maxRepeatingChar = a[j];
            }
            //When other characters become greater than k, we move window ahead.
            if(j-i+1 - maxRepeating > k){
                m[a[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }
        // cout << maxRepeatingChar << endl;
        
        if(m.size() == 1) return maxLen;
        
        //Find total frequency of maxRepeatingChar
        m[maxRepeatingChar] = 0;
        for(auto &c:a){
            if(c==maxRepeatingChar) m[maxRepeatingChar]++;
        }
        // cout << m[maxRepeatingChar]<< endl;
        
        if(m[maxRepeatingChar]<=maxRepeating) return maxLen-1;
        else return maxLen;
    }