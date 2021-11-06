Note: This is not a strict prerequisite, but solving Subset sum problem first will help understand the current problem with more understanding.
Problem: Subset Sum Problem (GFG)

 bool canPartition(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
		
		//If sum is odd, then there is no possible way to partition array in two halves having equal sum.
        if(sum % 2 != 0) return false;
		
		//If sum is even, then we have to search for sum/2 subset in the array, if that exists, then other half with equal sum also exists.
		//For e.g: 1,5,11,5 -> Sum = 22 -> Subset with target = sum/2 = 11 exists (1,5,5), then other half must be having sum 11.
        int target = sum/2;
        return isSubsetSum(a, target);
    }
	
bool isSubsetSum(vector<int> a, int sum){
        int n = a.size(), rows = n+1, cols = sum+1;
        bool t[rows][cols];
        
        //Initialization
        for(int i=1; i<cols; i++) t[0][i] = false;
        for(int j=0; j<rows; j++) t[j][0] = true;
        
        //Knapsack 0/1 code
        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                
                //Choice is there to include element or not
                if(a[i-1] <= j){
                    t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
                }
                
                //When element is greater than sum - No choice
                else if(a[i-1] > j){
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }