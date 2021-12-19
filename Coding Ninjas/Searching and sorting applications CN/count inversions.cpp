

ll merge(ll* a, int left, int mid, int right){
    ll i = left, j = mid, k= 0; //mid here is the start index of right array.
    ll temp[right - left + 1], counter = 0;

    while(i<mid && j<=right){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }
        else{
            temp[k] = a[j];
            j++;
            k++;
            counter += mid-i;
        }
    }

    while(i<mid){
        temp[k] = a[i];
        k++;
        i++;
    }

    while(j<=right){
        temp[k] = a[j];
        k++;
        j++;
    }

    //Copy temp array to original array
    for(int i=left, k=0; i<=right; i++,k++){
        a[i] = temp[k];
    }

    return counter;
}

ll mergeSort(ll* a, int left, int right){
    ll count = 0;
    if(right > left){
        ll mid = left + (right-left)/2;
        ll countLeft = mergeSort(a, left, mid);
        ll countRight = mergeSort(a, mid+1, right);
        ll myCount = merge(a, left, mid+1, right);

        return countLeft + countRight + myCount;
    }
    return count;
}

ll countInversions(ll* arr, int n){
    ll res = mergeSort(arr, 0, n-1);
    return res;
}