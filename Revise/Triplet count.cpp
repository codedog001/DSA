//Coding Ninja - Lang tools assignment
int fun(int* a, int k, int n, int low){
    int high = n-1, result =0;
    while(low<high){
        if(a[low] + a[high] < k) low++;
        else if(a[low] + a[high] > k) high--;
        else{
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
            
            result += lowCount * highCount;
            
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