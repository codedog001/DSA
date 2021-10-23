#include<queue>

bool isMaxHeap(int a[], int n) {
	for(int i=0; i<n; i++){
        int c1 = 2*i + 1;
        int c2 = 2*i + 2;
        if(c1<n){
            if(a[c1] > a[i]) return false;
            if(c2<n && a[c2] > a[i]) return false;
        }
    }
    return true;
}