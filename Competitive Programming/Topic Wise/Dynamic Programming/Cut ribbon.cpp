//Very similar to staircase problem

//1. Memoized

unordered_map<ll, ll> m;
ll fun(ll n, ll a, ll b, ll c){
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    if(m.count(n)) return m[n];
    
    return m[n] = 1+ max({fun(n-a,a,b,c), fun(n-b,a,b,c), fun(n-c, a, b, c)});
}
 
 
void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    cout<< fun(n, a, b, c) << endl;
    
    return;
}

//2. Top Down
void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    // cout<< fun(n, a, b, c) << endl;
    ll t[n+1];
    t[0] = 0;
    
    for(ll i=1; i<=n; i++){
        ll r1, r2, r3;
        r1 = r2 = r3 = INT_MIN;
        if(i>=a) r1 = t[i-a];
        if(i>=b) r2 = t[i-b];
        if(i>=c) r3 = t[i-c];
        
        t[i] = 1 + max({r1, r2, r3});
    }
    cout << t[n] << endl;
    return;
}
