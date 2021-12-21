//Coding Ninjas

bool isValid(vector<ll> &a, ll mid, ll k){
    ll n = a.size(), count = 0;
    for(ll i=0; i<n; i++){
        if(a[i] >= mid){
            count += a[i]/mid;
        }
        if(count>=k) return true;
    }
    return false;
}

void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, k, maxi = 0, mini= INT_MAX;
    cin >>  n >> k;
    vector<ll> a(n,0);
    for(auto &i: a) {
        cin >> i;
    }
    
    sort(a.begin(), a.end());
    mini = a[0], maxi = a[n-1];
    
    ll start = 0, end = maxi, res = 0;
    while(start <= end){
        ll mid = start + (end-start)/2;
        if(isValid(a,mid,k)){
            res = mid;
            start = mid+1;
        }
        else end = mid-1;
    }
    
    cout << res << endl;
    return;
}