#include<bits/stdc++.h>
using namespace std;

int m = pow(10,9) + 7;

int getProduct(int n){
    if(n<=1) return 1;
    
    int res = (((long)n%m) * ((long)getProduct(n-1) % m)) %m;
    return res;
}

int main(){
    
    // write your code here
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        cout << getProduct(n) << endl;
    }
    return 0;
}