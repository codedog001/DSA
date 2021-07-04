#include<iostream>
using namespace std;

long long int partitionSort(long long int * a, long long int start, long long int end){
    long long int pivot = a[start];
    long long int i=0;
    long long int counters=0;
    for(i=start+1;i<=end;i++){
        if(a[i]<=pivot){
            counters++;
        }
    }

    cout<<"A[start] is: "<<a[start]<<endl;
    long long int pivotIndex = counters+start;

    //Place pivot at pivotIndex by replacing it with element already present there.
    long long int temp = a[start];
    a[start] = a[pivotIndex];
    a[pivotIndex] = temp;

    //Sort the LHS and RHS of the array.
    i=start;
    long long int j=end;
    while(i<=pivotIndex && j>=pivotIndex){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j++;
        }
        if(i<pivotIndex && j<pivotIndex){
            long long int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;

}


void quickSort(long long int * a, long long int start, long long int end){
    if(start>=end){
        return;
    }
    if(start<end){
        cout<<"REC"<<endl;
        long long int c = partitionSort(a,start,end);
        quickSort(a,start,c-1);
        quickSort(a,c+1,end);
    }
}

int main(){
    long long int n=0,i=0;
    cout<<"Enter the size of array: "<<endl;
    cin >> n;
    long long int * a = new long long int[n];
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    long long int start =0;
    long long int end = n-1;

    quickSort(a,start,end);

    cout<<"RESULT: "<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    delete [] a;

}