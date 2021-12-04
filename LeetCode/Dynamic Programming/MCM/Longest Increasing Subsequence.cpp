int lis(int* arr, int n){
    int t[n];
    t[0] = 1;
    
    for(int i=1; i<n; i++){
        t[i] = 1;
        for(int j=i-1; j>=0; j--){
            if(arr[j] >= arr[i]) continue;
            else{
                int possibleAns = 1 + t[j];
                if(possibleAns > t[i]) t[i] = possibleAns;
            }
        }
    }
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        maxi = max(t[i], maxi);
    }
    
    return maxi;
}

int longestIncreasingSubsequence(int* arr, int n) {
	return lis(arr,n);
}