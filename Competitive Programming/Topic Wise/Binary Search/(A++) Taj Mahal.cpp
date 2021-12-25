//1. Using Binary Search - O(nlogn)
bool isValid(ll mid, ll i, ll ele, ll n){
    ll comp = i + (mid*n);
    return comp > ele;
    
}

void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    ll n;
    cin >> n;
    vector<ll> a(n+1,0), res(n+1);
    for(int i=1; i<n+1; i++) cin >> a[i];
    res[0] = INT_MAX;
    
    for(int i=1; i<n+1; i++){
        ll start = 0, end = 1e9, resi = 0;
        while(start <= end){
            ll mid = start + (end-start)/2;
            if(isValid(mid, i, a[i], n)){
                resi = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        res[i] = resi;
    }
    
    auto mini = min_element(res.begin(), res.end()) - res.begin();
    cout << mini << endl;

}



/*  Few general reminders:
    * Analyse constraints, look for bruteforce oppurtunities
    * Check every assumption (trivial or non-trivial)
    * int overflow, array bounds
    * binpow uses 1e9 + 7 as MOD
*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int t=-1;
    // cin >> t;
    // while (t--)
        solve();
}