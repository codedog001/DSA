#include<bits/stdc++.h>
using namespace std;

int findMinInitialHealth(vector<vector<int>>& t, int row, int col, int er, int ec, vector<vector<int>>& dp){
	if(row ==er && col == ec) return 1;
    if(row > er || col > ec) return INT_MAX;
    
    if(dp[row][col] != INT_MAX) return dp[row][col];
    
    int down =  INT_MAX, right = INT_MAX;
    if(row+1<=er) down = findMinInitialHealth(t, row+1, col, er, ec, dp) - t[row+1][col];
    if(col+1<=ec) right = findMinInitialHealth(t, row, col+1,er, ec, dp) - t[row][col+1];
    
    int res = min(down,right);
    if(res <=0) res = 1;
    
    // cout << res-t[row][col] << endl;
    return dp[row][col] = res;
}

void solve(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> t(r, vector<int>(c,0));
    vector<vector<int>> dp(r+1, vector<int>(c+1,INT_MAX));
    
    for(auto &i:t){
        for(auto &d:i){
            cin >> d;
        }
    }
   
    cout << findMinInitialHealth(t, 0, 0, r-1, c-1,dp) << endl;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    // write your code here
    return 0;
}