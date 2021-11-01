#include<unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int, int> m;
    int res = 0;
    for(int i=0; i<n; i++){
        int largeTarget = arr[i] + k;
        res+=m[largeTarget];
        
        if(k!=0){
            int smallTarget = arr[i] - k;
            res+=m[smallTarget];
        }
        
        m[arr[i]]++;
    }
    return res;
}