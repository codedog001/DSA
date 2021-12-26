#include<bits/stdc++.h>
using namespace std;

int m = pow(10,9)+7;
int powerFun(int x, int y){
    if(y<=0) return 1;
    if(y==1) return x;
    
    int ans = ((long)(x%m) * (long)(powerFun(x,y-1) % m)) % m;
    return ans;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        cout << powerFun(x,y) << endl;
    }
    return 0;
}