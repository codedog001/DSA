#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll findMaxSum(ll* dp, ll* freq){
    dp[0] = 0;
    dp[1] = freq[1];
    
    for(ll i=2; i<=1000; i++){
        dp[i] = max(dp[i-2] + (freq[i] * i), dp[i-1]);
    }
    
    return dp[1000];
}

int main(){
    ll t; 
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll dp[1002]={0}, freq[1002]={0};
        for(ll i=0; i<n; i++){
            ll x;
            cin >> x;
            freq[x]+=1;
        }
        cout << findMaxSum(dp, freq) << endl;
    }
}