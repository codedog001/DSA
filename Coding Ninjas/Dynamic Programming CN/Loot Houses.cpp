//N<=10^5, so NEED A WAY IN WHICH MATRIX NEEDED TAKES SPACE OF: O(N), not O(N*N) - IT WORKED!!!

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;




ll findMaxValue(vector<ll> &a, ll index){
    
    ll n= a.size();
    if(index >= n) return 0;
    
    
    if(dp[index] !=  -1) return dp[index];
    
    ll fromI = INT_MIN, fromIPlus1 = INT_MIN;
    fromI = a[index] + findMaxValue(a, index+2);
    if(index + 1 < n) fromIPlus1 = a[index+1] + findMaxValue(a, index + 3);

    ll res = max(fromIPlus1, fromI);
    
    return dp[index] = res;
}

int main(){
    
    // write your code here
    ll n; 
    cin >> n;
    vector<ll> a(n,0);
    dp.resize(n+10,-1);
    for(auto& i:a) cin >> i;
    
    cout << findMaxValue(a,0) << endl;
    return 0;
}