GFG	
    //1. Top Up (Memoization)
    int perfectSum(int arr[], int n, int sum){
	    vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
	    return pum(arr, n, sum, t);
	}
	int pum(int arr[], int n, int sum, vector<vector<int>>& t)
	{
        // Base case
        if(sum ==0) return 1;
        if(n <= 0) return 0;
        
        //Check if answer already exists
        if(t[n][sum] != -1) return t[n][sum] % 1000000007;
        
        //Choice Diagram
        if(arr[n-1] <= sum){
            return t[n][sum] = (pum(arr, n-1, sum-arr[n-1],t) +pum(arr, n-1, sum,t))  % 1000000007; 
        }else{
            return t[n][sum] = pum(arr, n-1, sum,t) % 1000000007;
        }
        
	}

    //2. Bottom Down (Dynamic Programming)
    	int perfectSum(int arr[], int n, int sum){
	    //Bottom Up approach
	    
	    int t[n+1][sum+1];
	    
	    //Initialization
	    for(int i=0; i<sum+1; i++) t[0][i] = 0;
	    for(int i=0; i<n+1; i++) t[i][0] = 1;
	    
	    //Knapsack code
	    for(int i=1; i<n+1; i++){
	        for(int j=1; j<sum+1; j++){
	            if(arr[i-1] <= j){
	                t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % 1000000007;
	            }else{
	                t[i][j] = t[i-1][j] % 1000000007;
	            }
	        }
	    }
	    return t[n][sum] % 1000000007;
	}