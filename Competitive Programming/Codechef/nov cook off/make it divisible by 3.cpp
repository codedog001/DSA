void solve() {

    // Effort might not always be fruitful, but it's never wasted.
    ll n, sum=0, res = 0;
    cin >> n;
    vector<ll> v(n,0);
    
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        v[i] = x%3;
        sum += x%3;
    }
    if(sum %3 !=0) cout << -1 << endl;
    else{
        vector<ll> a(3,0);
        for(int i=0; i<n; i++){
            a[v[i]]++;
        }
        int numOfOneTwoRemPairs = min(a[1], a[2]);
        res += numOfOneTwoRemPairs;
        int remaining = max(a[1], a[2]) - numOfOneTwoRemPairs;
        res += 2 * (remaining/3);
        cout << res << endl;
    }
    
    return;
}