class Solution {
public:
long long merge(long long* arr, int si, int mid, int ei){
    int i=si, j=mid, k=0;
    long long temp[ei-si+1], counter = 0;
    
    //Only additional step to count reverse pairs.
    while(i<mid){
        while(j<=ei && arr[i] > 2*arr[j]) j++;
        counter += j-mid;
        i++;
    }
    
    //Normal Merge Step
    i=si, j=mid;
    while(i<mid && j<=ei){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    
    while(i<mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    
    while(j<=ei){
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(int i=si, k=0; i<=ei; i++, k++){
        arr[i] = temp[k];
    }
    return counter;
}


long long mergeSortHelper(long long* arr, int si, int ei){
    if(si >= ei) return 0;
    long long mid = si + (ei - si)/2;
    long long c1 = 0;
    c1 += mergeSortHelper(arr, si, mid);
    c1 += mergeSortHelper(arr, mid+1, ei);
    c1 += merge(arr, si, mid+1, ei);
    
    return c1;
}

    int reversePairs(long long* arr, int n) {
        return (int) mergeSortHelper(arr, 0, n-1);
    }
};