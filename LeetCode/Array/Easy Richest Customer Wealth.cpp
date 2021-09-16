int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        if(accounts.empty()) return max;
        for(auto &g:accounts){
            int temp = accumulate(g.begin(), g.end(), 0);
            if(temp>max) max = temp;
        }
        return max;
    }