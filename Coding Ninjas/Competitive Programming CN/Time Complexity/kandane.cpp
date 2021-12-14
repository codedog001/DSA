#include<iostream>
using namespace std;

int kandanes(int* a, int n){
    int best = 0, cursum = 0;
    for(int i=0; i<n; i++){
        cursum += a[i];
        if(cursum < 0) cursum =0;
        if(cursum > best) best = cursum;
    }
    return best;
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }

    cout << "largest sub sum: " << kandanes(a, n) << endl;
}