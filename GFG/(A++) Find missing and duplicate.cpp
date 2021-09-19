 
    
    int *findTwoElement(int *arr, int n) {
        int *res = new int[2];
        int repeating =0, missing = 0;
        //Swap sort - It won't work if arr contains 0. Because arr[-1] will throw error.
        int i=0;
        while(i<n){
            if(arr[i] != arr[arr[i] -1]){
                swap(arr[i], arr[arr[i]-1]);
            }else{
                i++;
            }
        }
        i=0;
        while(i<n){
            if(arr[i] != i+1){
                repeating = arr[i];
                missing = i+1;
                break;
            }
            i++;
        }
        res[0] = repeating;
        res[1] = missing;
        return res;
    }