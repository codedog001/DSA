//1. Bottom Up approach
bool isSubsetSum(int n, int arr[], int sum){
        bool t[n+1][sum+1];
        
        //Initialization
        for(int i=1; i<sum+1; i++) t[0][i] = false;
        for(int j=0; j<n+1; j++) t[j][0] = true;
        
        //Knapsack code
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }