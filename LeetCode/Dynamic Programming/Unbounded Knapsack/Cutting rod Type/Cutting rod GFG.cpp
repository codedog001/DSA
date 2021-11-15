int cutRod(int price[], int n) {
        int len[n];
        for(int i=1; i<=n; i++) len[i-1] = i;
        
        int size = n; //Size of profit array.
        int w = n; //Weight (w) rod cutting problems is length of rod
        
        int t[size+1][w+1];
        
        //Initialization.
        for(int i=0; i<size+1; i++) t[i][0] = 0;
        for(int j=0; j<w+1; j++) t[0][j] = 0;
        
        //Unbounded Knapsack
        for(int i=1; i<size+1; i++){
            for(int j=1; j<w+1; j++){
                if(len[i-1] <= j){
                    t[i][j] = max(price[i-1] + t[i][j-len[i-1]], 0 + t[i-1][j]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[size][w];
    }
