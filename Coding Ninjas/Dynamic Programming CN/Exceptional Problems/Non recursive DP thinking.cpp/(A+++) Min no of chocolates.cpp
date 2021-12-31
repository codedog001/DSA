//Save results once from left to right and then from right to left in dp, the max of both would be 
//final result.

#include<bits/stdc++.h>
using namespace std;

void findChocolates(vector<int>& a, vector<int>& dp){
    int res = 1, i=1, n= a.size();
    dp[0] = 1;
    while(i<n){
        res = 1;
        while(i<n && a[i] > a[i-1]) {
            dp[i] = 1+dp[i-1];
        	i++;
        }
        
        while(i<n && a[i] <= a[i-1]){
            dp[i] =1;
            if(i<n-1 && a[i] > a[i+1]) dp[i] += 1;
            i++;
        }
    }
}

int main(){
    
    // write your code here
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> dp(n,0);
        vector<int> a(n);
        
        for(auto& i:a) cin >> i;
        
        findChocolates(a, dp);
        
        reverse(a.begin(), a.end());
        
        vector<int> dp2(n,0);
        findChocolates(a, dp2);
        reverse(dp2.begin(), dp2.end());
        
        int res = 0;
        for(int i=0; i<n; i++){
            res += max(dp[i], dp2[i]);
        }
        
        cout << res << endl;
    }
    
    return 0;
}