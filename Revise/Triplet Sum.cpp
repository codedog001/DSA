//Coding Ninja - Lang tools assignment
int fun(int* a, int k, int n, int low){
    int high = n-1, result =0;
    while(low<high){
        if(a[low] + a[high] < k) low++;
        else if(a[low] + a[high] > k) high--;
        else{
            //When we reach a[low] == a[high], we are sure, that we aren't missing anything 
            //in the middle that could form a pair, because a[low] is equal to a[high] and hence we can increase
            //result and return the answer.

            if(a[low] == a[high]){
                int count = high-low+1;
                result += (count *(count-1))/2;
                return result;
            }
            int lowCount = 1, highCount =1;
            while(low<high && a[low] == a[low+1]) {
                low++;
                lowCount++;
            }
            while(low < high && a[high] == a[high-1]){
                high--;
                highCount++;
            } 
            
            result += lowCount * highCount; // NOt returning result immedeately when a[low] != a[high], 
            //consider case: 033344445555 target: 8, a[i] = 0, k=8-0 = 8
            //when we count 0,3 and 5 pair, if we return result here only, we will never be able count 0 and 4,4 pair 
            //Basically, pair count might increase when a[low] != a[high], so until we reach low==high, we won't return result.
            
            low++;
            high--;
        }
    }
    return result;
}

int tripletSum(int *a, int n, int num)
{
	//Write your code here
    sort(a, a+n);
    int res = 0;
    for(int i=0; i<n; i++){
        int k = num - a[i], start = i+1;
        res += fun(a,k,n,start);
    }
    return res;
}