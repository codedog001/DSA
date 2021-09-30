vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                //Ignore 0s
                if(land[i][j] == 0) continue;

                //Find Right most column of 1 marked block
                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }

                //Find bottom most row of 1 marked block
                int r2 = i;
                while(r2 < m && land[r2][j] == 1) {
                    r2++;
                }
                
                //Find bottom right most of 1 marked block
                c1 = c1==0 ? c1 : c1-1;
                r2 = r2==0 ? r2 : r2-1;

                //Push these coordinates
                //{r1, c1} = {i, j}
                //{r2, c2} = {r2, c1}
                result.push_back({i, j, r2, c1});
                
                //Mark the land traversed as 0, so as to not consider them as a valid answer again.
                for(int k = i; k<=r2; k++) {
                    for(int l = j; l<=c1; l++) {
                        land[k][l] = 0;
                    }
                }
            }
        }
        return result;
    }