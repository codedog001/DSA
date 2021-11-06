GFG Problem

int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range = 0;
	    for(int i=0; i<n; i++) range += arr[i];
	    
	    //We need to minimize s2-s1 => range - 2s1
	    //Now we need to find maximum s1 within half sum - So call isSubsetSum to fill the table
	    //until half sum, and within that find largest sum that exists.
	    
	    //Say {1,2,7} -> target = sum/2 = 10/2 = 5.
	    //Largest sum that exists under 5 is => 1+2=3, and 7-3 = 4 which is correct answer.
	    
	    int target = range/2;
	    vector<vector<int>> t(n+1, vector<int>(target+1, -1));
	    
	    //Fill the table 
	    isSubsetSum(arr,n,target,t);
	    
	    //Search for largest sum in the table in row where i=n, i.e. all elements exist.
	    for(int j=target; j>=0; j--){
	        int maxS1WithinHalfRange = j;
	        if(t[n][j] == 1) {
	            int minDifference = range - 2*maxS1WithinHalfRange;
	            return minDifference;
	        }
	    }
	    //Never runs
	    return -1;
	} 

int isSubsetSum(int arr[], int n, int sum, vector<vector<int>>& t){
        for(int i=0; i<sum+1; i++) t[0][i] = 0;
        for(int j=0; j<n+1; j++) t[j][0] = 1;
        
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
	