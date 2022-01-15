void merge(int input[], int si, int mid, int ei){
    int i = si, j= mid, k=0;
	int temp[ei-si+1];
    
    while(i<mid && j<=ei){
        if(input[i] < input[j]){
            temp[k] = input[i];
            i++;
            k++;
        }else if(input[j]<= input[i]){
            temp[k] = input[j];
            k++;
            j++;
        }
    }
    
    while(i<mid){
        temp[k] = input[i];
        k++;
        i++;
    }
    
    while(j<=ei){
        temp[k] = input[j];
        k++;
        j++;
    }
    
    for(int i=si, k=0; i<=ei; i++,k++){
        input[i] = temp[k];
    }
}


void mergeSortHelper(int input[], int si, int ei){
    if(si >= ei) return;
    int mid = si + (ei-si)/2;
    mergeSortHelper(input, si, mid);
    mergeSortHelper(input, mid+1, ei);
    merge(input, si, mid+1, ei);
}


void mergeSort(int input[], int size){
	// Write your code here
    if(size==0 || size==1) return;
    
    mergeSortHelper(input, 0, size-1);
        
}
