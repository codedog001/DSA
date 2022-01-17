    static bool cmp(const pair<int, int>& a, const pair<int, int>& b){
         return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> res;
        for(int i=0; i<n; i++){
            res.push_back({start[i], end[i]});
        }
        
        sort(res.begin(), res.end(), cmp);
        
        int meetings = 1, endTime = res[0].second;
        for(int i=1; i<n; i++){
            if(res[i].first > endTime) {
                meetings++;
                endTime = res[i].second;
            }
        }
        
        return meetings;
    }