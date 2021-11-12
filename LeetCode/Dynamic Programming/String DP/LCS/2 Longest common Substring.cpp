int longestCommonSubstr(string a, string b, int x, int y)
    {
        int res = 0;
        int t[x+1][y+1];
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                if(i==0 || j== 0) t[i][j] = 0;
                else{
                    if(a[i-1] == b[j-1]){
                        t[i][j] = 1+ t[i-1][j-1];
                        
                        //Store length of largest substring
                        res = max(t[i][j], res);
                    }
                    else t[i][j] = 0;
                }
            }
        }
        return res;
    }