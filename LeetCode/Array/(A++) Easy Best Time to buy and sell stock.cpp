int maxProfit(vector<int>& p) {
        int maxProf = 0, minPrice = INT_MAX;
        for(int i=0; i<p.size(); i++){
            minPrice = min(minPrice, p[i]);
            int curProfit = p[i] - minPrice;
            maxProf = max(maxProf, curProfit);
        }
        return maxProf;
    }