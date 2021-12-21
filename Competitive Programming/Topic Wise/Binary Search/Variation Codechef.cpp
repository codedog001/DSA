//1. Binary Search
void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    
    for(auto &i:a) cin >> i;
    sort(a.begin(), a.end());
    ll res = 0;
    
    for(ll i=0; i<n; i++){
        ll target = a[i]+k;
        ll index = lower_bound(a.begin(), a.end(), target) - a.begin();
        res += n-index;
    }
    cout << res << endl;
    return;
}

//2. 2 Pointer
void solve() {
    // Effort might not always be fruitful, but it's never wasted.
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    
    for(auto &i:a) cin >> i;
    sort(a.begin(), a.end());
    ll res = 0,j=0,i=0;
    
    while(j<n){
        if(a[j] - a[i] < k) j++;
        else if(a[j] - a[i] >= k){
            res+= n-j;
            i++;
            j= i+1;
        }
    }
    cout << res << endl;
}