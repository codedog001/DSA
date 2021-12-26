void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    int n;
    cin >> n;
    int a[500000+2];
    memset(a,0, sizeof(a));
    ll maxX = 0;
    for(int i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        
        if(y>a[x/2]) a[x/2] = y;
        maxX = max(x/2, maxX);
    }
    ll totalHeight = 0;
    
    for(int i=maxX; i>0; i--){
        if(a[i] < a[i+1]) a[i] = a[i+1];
        totalHeight += a[i];
    }
    ll totalBlocks = totalHeight * 2;
    
    cout << totalBlocks << endl;
    return;
}