bool checkIfPangram(string sentence) {
        unordered_set<char> m;
        for(auto &c:sentence){
            m.insert(c);
            if(m.size() == 26) break;
        }
        if(m.size() == 26) return true;
        else return false;
    }