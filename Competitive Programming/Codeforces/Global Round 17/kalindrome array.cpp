#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;
 
// Vectors
#define pb push_back
#define all(a) a.begin(), a.end()
 
// Pairs
#define mp make_pair
#define ff first
#define ss second
 
#define endl "\n"
 
// Debugging header file
#ifndef ONLINE_JUDGE
#include <debug.hpp>
#else
#define dbg (...)
#endif
 
// Constants
const int MOD = 1e9 + 7;                                // 998244353 (something FFT, idk yet)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // grids
const double PI = acos((double)-1);
const int MAX_N = 1e5 + 1;
 
// Utility functions
 
// Binary Exponentiation
long long binpow(long long a, long long b, long long m = MOD)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
// Fast Modulo - https://codeforces.com/blog/entry/72722?#comment-570232
inline void addmod(int &a, int val, int p = MOD)
{
    if ((a = (a + val)) >= p)
        a -= p;
}
inline void submod(int &a, int val, int p = MOD)
{
    if ((a = (a - val)) < 0)
        a += p;
}
 
// // Graphs
// vector<int> g[MAX_N];
// vector<bool> vis(MAX_N);
 
pair<bool,ll> isPalindrome(vector<ll>& a){
    ll n= a.size();
    for(int i=0; i<a.size(); i++){
        if(a[i] != a[n-1-i]) {
            return {false, i};
        }
    }
    return {true,0};
}
 
void solve() {
 
    // Effort might not always be fruitful, but it's never wasted.
    
    ll n;
    cin >>n;
    vector<ll> a(n,0);
    
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        a[i] = x;
    }
    pair<bool, ll> t = isPalindrome(a);
    if(t.first || a.size() <=2){
        cout <<"YES" << endl;
        return;
    }else{
        ll index = t.second;
        ll ele = a[index];
        vector<ll> b;
        for(auto &x:a){
            if(x!=ele) b.push_back(x);
        }
        t = isPalindrome(b);
        if(t.first){
            cout <<"YES" << endl;
            return;
        }else{
            ll index2 = n-index-1;
            ll ele2 = a[index2];
            vector<ll> c;
            for(auto &x:a){
                if(x!=ele2) c.push_back(x);
            }
            t = isPalindrome(c);
            if(t.first){
                cout <<"YES" << endl;
                return;
            }
        }
        cout <<"NO" << endl;
    }
    
    return;
    
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
    //
 
    int t;
    cin >> t;
    while (t--)
        solve();
}