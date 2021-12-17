int binarySearch(vector<int> &arr, int key){
    int start = 0, int end = arr.size()-1;
        while(start<=end){
            int mid = start + (end -start)/2;
            if(arr[mid] == key) return mid;
            else if(arr[mid] < key) start = mid+1;
            else end = mid-1;
        }
        return -1;
    } 