vector<bool> kidsWithCandies(vector<int>& a, int extraCandies) {
        int maxi = a[0];
        vector<bool> res;
        for(auto &g:a) maxi = max(g,maxi);
        for(auto &g:a){
            if(g+extraCandies >= maxi) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }