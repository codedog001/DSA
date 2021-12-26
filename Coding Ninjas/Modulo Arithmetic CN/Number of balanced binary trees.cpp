#include<bits/stdc++.h>
using namespace std;
int m = pow(10,9) + 7;
int findResult(int h){
    if(h==0 || h==1) return 1;
    
	
    int x = findResult(h-1);
    int y = findResult(h-2);
    
    long ans1 = (long) x*x;
    long ans2 = (long) x*y*2;
    
    int res1 = ans1 %m;
    int res2 = ans2 %m;
    
    return (res1 + res2) %m;
}

void solve(){
    int h;
    cin>>h;
    cout << findResult(h) << endl;
}
int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}