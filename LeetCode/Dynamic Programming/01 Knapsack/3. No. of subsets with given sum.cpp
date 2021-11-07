GFG	
    
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
        if(t[n][sum] != -1) return t[n][sum];
        
        //Choice Diagram
        if(arr[n-1] <= sum){
            return t[n][sum] = (pum(arr, n-1, sum-arr[n-1],t) +pum(arr, n-1, sum,t))  % 1000000007; 
        }else{
            return t[n][sum] = pum(arr, n-1, sum,t);
        }
        
	}