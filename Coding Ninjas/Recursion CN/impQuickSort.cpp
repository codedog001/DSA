#include<iostream>
using namespace std;


int partition(int * a, int start, int end){
    int pivot = a[start];
    int count =0;
    
    //Find index at which pivot is to be inserted
    for(int i=start+1;i<=end;i++){
        if(a[i]<=pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    
    int temp = a[start];
    a[start]=a[pivotIndex];
    a[pivotIndex] = temp;
    
    //Sort the LHS and RHS of the pivot.
    int i = start;
    int j = end;
    
    while(i<=pivotIndex && j>=pivotIndex){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            int temper = a[i];
            a[i] = a[j];
            a[j] = temper;
            i++;
            j--;
        }
    }
 
    
    return pivotIndex;
}

void doQuick(int * a, int start, int end){

    if(start>=end){
        return;
    }
    if(start<end){
        int c = partition(a, start, end);
        doQuick(a, start, c-1);
        doQuick(a, c+1, end);
    }
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
     
  */
    int start = 0;
    doQuick( input, start, size-1);
	
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


