class Solution {
public:
    int search(vector<int>& arr, int key) {
        int minIndex = findMin(arr); //find the index of the smallest value using binary search.
        int end= arr.size()-1, index1, index2 = -2;
        
        //Do binary search in both halves
        index1 = binarySearch(arr, minIndex, end, key);
        if(index1 == -1) index2 = binarySearch(arr, 0, minIndex-1, key);
        return max(index1, index2);
    }
    
    int findMin(vector<int>& arr) {
        int lo=0, hi=arr.size()-1, mid, prev, next,  n=arr.size();
		
		//In case we have a sorted array, min element will be at index 0.
        if(arr[0]<arr[n-1]) return 0;
		
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            prev=(mid-1+n)%n;
            next=(mid+1)%n;
            if(arr[mid]<=arr[prev] and arr[mid]<=arr[next]) return mid;
            if(arr[0]<=arr[mid]) lo=mid+1;
            else if(arr[mid]<=arr[n-1]) hi=mid-1;
        }
    return -1;
    }
    
    int binarySearch(vector<int> &arr, int start, int end, int key){
        while(start<=end){
            int mid = start + (end -start)/2;
            if(arr[mid] == key) return mid;
            else if(arr[mid] < key) start = mid+1;
            else end = mid-1;
        }
        return -1;
    } 
};