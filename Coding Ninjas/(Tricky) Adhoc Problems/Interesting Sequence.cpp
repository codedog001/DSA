ll findCost(vector<ll>& a, ll mini, ll maxi, ll k, ll l){
    ll n = a.size(), minCost = 1e15;

    //Finding cost of making all elements equal to pivot. Pivot could be any value b/w
    //min and max element of the array.
    for(ll i=mini; i<=maxi; i++){
        ll pivot = i, increase = 0, decrease = 0, totalCost = 0;
        for(ll j=0; j<n; j++){
            if(a[j] > pivot) decrease += a[j] - pivot;
            if(a[j] < pivot) increase += pivot - a[j];
        }
        if(increase < decrease) continue;
        ll decreaseCost = decrease * k;
        ll increaseCost = (increase - decrease) * l;
        
        totalCost = decreaseCost + increaseCost;
        minCost = min(totalCost, minCost);
    }
    return minCost;
}
void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, k, l;
    cin >> n >> k >> l;
    vector<ll> a(n,0);
    ll maxi = INT_MIN, mini = INT_MAX;
    for(auto& i:a) {
        cin >> i;
        maxi = max(maxi, i);
        mini = min(mini, i);
    }
    if(n== 1 || maxi == mini) cout << 0 << endl;
    else{
        ll res = findCost(a,mini, maxi, k, l);
        cout << res << endl;
    }
    return;
}
