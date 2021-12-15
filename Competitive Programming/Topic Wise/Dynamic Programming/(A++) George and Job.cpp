//1. Top down
void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, m, k;
    cin >> n >> m >> k;
    ll dp[5005][5005];
    ll a[5005];
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    
    for(ll i=1; i<=k; i++){
        for(ll j=m; j<=n; j++){
            dp[i][j] = max(a[j]-a[j-m] + dp[i-1][j-m], 0 + dp[i][j-1]);
        }
    }
    cout << dp[k][n] << endl;
    
    
    
    return;
}
 

//2. Memoized
vector<vector<ll>> dp;

ll a[5005];
ll fun(ll n, ll m, ll k, ll index){
    if((n-index) < m-1 || k<=0) return 0;
     
    //Sum of current window
    if(dp[k][index] != -1) return dp[k][index];
    ll sum = a[index+m-1]-a[index-1];
    return dp[k][index] = max(sum + fun(n,m,k-1,index+m), 0+ fun(n,m,k,index+1));
    
}
 
void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, m, k;
    cin >> n >> m >> k;
    dp.resize(k+1, vector<ll>(n+1,-1));
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
 
    cout << fun(n,m,k,1) << endl;
    
    
    
    return;
}