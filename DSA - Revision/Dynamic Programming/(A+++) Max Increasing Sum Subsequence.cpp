int maxSumIS(int arr[], int n) {  
	// Your code goes here
	vector<int> dp(n,0);
    dp[0] = arr[0];
	    
	for(int i=1; i<n; i++){
	    dp[i] = arr[i];
	    for(int j=0; j<i; j++){
            int newSum = arr[i] + dp[j];
	        if(arr[i] > arr[j] && dp[i] < newSum) dp[i] = newSum;
	    }
	}
	    
	int res = 0;
    for(int i=0; i<n; i++) res = max(dp[i], res);
	    
	return res;
}  