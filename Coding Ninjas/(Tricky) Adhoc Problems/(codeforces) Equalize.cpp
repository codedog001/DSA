void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, cost= 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    for(ll i=0; i<n; i++){
        if(a[i] != b[i]){
            if(i+1 < n && a[i] == b[i+1] && a[i+1] == b[i]){
                cost++;
                i++;
            }
            else cost++;
        }
    }
    cout << cost << endl;
    
    return;
}
 