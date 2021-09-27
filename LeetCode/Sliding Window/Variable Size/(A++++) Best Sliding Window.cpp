Best possible explanation: https://leetcode.com/problems/replace-the-substring-for-balanced-string/discuss/409017/JAVA-Sliding-Window-Solution-with-Explanation

// Just dry run according to his explanation/code, and you'll find out how great this question is. I have added comments to make it somewhat easier to understand.

int balancedString(string s) {
        unordered_map<char, int> m;
        
        //1. Store the frequency of each char in m
        for(auto &g:s) m[g]++;
        
        //2. Store extra characters of string s in another string
        string charToRemove = "";
        
        int len = s.size();
        for(auto &g: m){
            
            //Char with 0 frequency after subtraction are in right amount.
            g.second -= len/4;
            
            //Now store extra characters.
            if(g.second > 0){
                for(int i=0; i<g.second; i++){
                    charToRemove += g.first;
                }
            }
        }
        cout << charToRemove << endl;
        if(charToRemove.size() == 1) return 1;
        if(charToRemove.empty()) return 0;
        
        //Now charToRemove contains the characters which are to be removed, so now we have to find a minimum substring in s that contains all the characters.
        
        //3. Sliding window to find minimum substring containing all characters of charToRemove in s.
        
        //Store frequency of char of charToRemove in a map.
        
        unordered_map<char, int> mp;
        for(auto &c: charToRemove) mp[c]++;
        
        int i=0, j=0, count = mp.size(); //Count stores no. of unique characters in charToRemove.
        int minLen = INT_MAX;
        
        while(j<s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            if(count > 0) j++;
            else if(count == 0){
                minLen = min(minLen, j-i+1);
                while(count == 0){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1) count++;
                    }
                    minLen = min(minLen, j-i+1);
                    i++;
                }
                j++;
            }
        }
        return minLen;
    }