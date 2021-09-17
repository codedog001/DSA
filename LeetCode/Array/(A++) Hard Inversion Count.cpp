

//Rest is normal mergesort, the merge part is where count is adding.
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k; //Let array = 1,3,4,2,5 
    int count = 0; 
 
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) {

        //Left -> 1, 3, 4 and Right -> 2,5. 
        //1 and 2 will initially have pointer.
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++]; //1 and 2 getting merged won't increase count becasue 1<2. 1 will get in result array, pointer will move to 3 in left, but stay at 2 on right part.
        }
        //Now 3 on left and 2 on right has pointer. 2 will be chosen, and it will make pair with all elements on left part. 
        //Look up in original array, pairs with 2 will be: (3,2), (4,2) -> and those are the elements in left part.
        //That's why when a small element is being picked up from the right, all the numbers on left are a pair with it.
        else {
            temp[k++] = arr[j++]; 
            //This is the most important part.
            count = count + (mid - i);
        }
    }
 
   //Copy the remaining elements of left subarray to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    //Copy the remaining elements of right subarray to temp
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return count;
}


int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, count = 0;
    if (right > left) {
        
        mid = (right + left) / 2;
        count += _mergeSort(arr, temp, left, mid);
        count += _mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}