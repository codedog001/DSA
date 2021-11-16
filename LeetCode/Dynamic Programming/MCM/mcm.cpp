//1. Recursive Solution
int solve(int arr[], int i, int j){
        //Base case
        if(i==j) return 0;
        
        int res = INT_MAX;
        
        //Move k
        
        for(int k=i; k<=j-1; k++){
            //temp = c1 + c2 + c3
            int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
            res = min(temp, res);
        }
        
        return res;
    }
    int matrixMultiplication(int n, int arr[]){
        int i=1, j=n-1;
        return solve(arr, i, j);
    }