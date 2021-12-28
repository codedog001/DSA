// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.
// W can be pretty large so output the answer % mod(10^9 + 7)

ll findWays(ll v, vector<ll>& a, ll index, vector<vector<ll>>& dp){
    if(v<=0) return 1;
    if(index<=0) return 0;
    
    if(dp[index][v] != -1) return dp[index][v];
    if(a[index-1] <= v){
        return dp[index][v] = (findWays(v-a[index-1], a, index, dp)%mod + findWays(v,a,index-1, dp)%mod)%mod ;
    }
    else return dp[index][v] = findWays(v, a, index-1, dp)%mod;
}

void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    
    ll n; //n is no. of denominations.
    cin >> n;
    
    vector<ll> a(n,0);
    for(auto& i:a) cin >> i;
    ll v;
    cin >> v;
    vector<vector<ll>> dp(n+1, vector<ll>(v+1, -1));
    cout << findWays(v,a, n, dp)<<endl;
    return;
}