//1. Bottom Up approach (Dynamic Programming)
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

//2. Top Down Approach (Memoization)
    bool isSubsetSum(int n, int arr[], int sum){
       vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
       return helper(n,arr,sum,t);
    }
    
    bool helper(int n, int arr[], int sum, vector<vector<int>>& t){
         //Base case
        if(sum==0) return 1;
        if(n<=0) return 0;
        
        if(t[n][sum] != -1) return t[n][sum];
        //Choice diagram
        if(arr[n-1] <= sum){
            t[n][sum] = helper(n-1, arr, sum-arr[n-1],t) || helper(n-1, arr, sum, t);
            return t[n][sum];
        }
        else {
            t[n][sum] = helper(n-1, arr, sum,t);
            return t[n][sum];
        }
    }
