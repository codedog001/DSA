void solve() {
    // Effort might not always be fruitful, but it's never wasted.
    ll n;
    cin >> n;
    vector<ll> a(100005,0);
    for(ll i=1; i<=n; i++) cin >> a[i];
        
    if(isPossible(a,n)){
        getResult(a, n);
    }
    
	return;
}

void getResult(vector<ll>& a, ll n){
    ll swapsNeeded = 0;
    for(ll i=1; i<=n; i++){
        if(a[i] == i) continue;
			
        if(i < n && a[i+1] == i) {
            swapsNeeded++;
            swap(a[i], a[i+1]);
        }
        else if(i < n-1 && a[i+2] == i){
            a[i+2] = a[i+1];
            a[i+1] = a[i];
            a[i] = i;                
            swapsNeeded+=2;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << swapsNeeded << endl;
}

bool isPossible(vector<ll>& a, ll n){
    for(int i=1; i<=n; i++){
        if(abs(a[i] - i) > 2){
            cout << "NO" << endl;
            return false;
        }
    }
    return true;
}