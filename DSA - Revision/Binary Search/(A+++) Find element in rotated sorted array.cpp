class Solution {
public:
    int binarySearch(vector<int> &arr, int start, int end, int key){
        while(start<=end){
            int mid = start + (end -start)/2;
            if(arr[mid] == key) return mid;
            else if(arr[mid] < key) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    
    int findBreakPoint(vector<int>& arr) {
        int lo=0, hi=arr.size()-1;
        int mid;
        int prev, next;
        int n=arr.size();
        if(arr[0]<arr[n-1])
            return 0;
        while(lo<=hi){

            mid=lo+(hi-lo)/2;

            prev=(mid-1+n)%n;
            next=(mid+1)%n;
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[next])
                return mid;

            if(arr[0]<=arr[mid])
                lo=mid+1;

            else if(arr[mid]<=arr[n-1])
                    hi=mid-1;
        }
    return -1;
    }
    
    int search(vector<int>& arr, int key) {
        int minIndex = findBreakPoint(arr);
        int end= arr.size()-1;
        int index1, index2 = -2;
        index1 = binarySearch(arr, minIndex, end, key);
        if(index1 == -1) index2 = binarySearch(arr, 0, minIndex-1, key);
        return max(index1, index2);
    }
};