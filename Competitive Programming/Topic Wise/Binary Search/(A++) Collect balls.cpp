//Time Complexity: O((log n)^2)
//Binary search takes logn time, and isValid is taking logn time. -> logn * logn.

bool isValid(ll k, ll n){
    ll sharma=0,singh=0;
    while(n>0){
        sharma += min(n,k);
        n-=k;
        if(n>0) singh += n/10;
        
        n-= (n/10);
    }
    
    
    return sharma >= singh;
}

void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n, res = 0;
    cin >> n;
    ll start = 1, end = (n/2);
    
    while(start<=end){
        ll mid = start + (end-start)/2;
        if(isValid(mid,n)){
            res = mid;
            end = mid-1;
        }
        else start = mid+1;
    }
    cout << res << endl;
    
    return;
}