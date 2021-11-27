//Rearrange given string to palindrome if possible else output -1.
#include <bits/stdc++.h>
//
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

bool isPalindrome(string& s){
    int i=0,n = s.size(),j=n-1;
    while(i<=j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve() {

    // Effort might not always be fruitful, but it's never wasted.
    string str;
    cin >> str;
    unordered_map<char, pair<int, stack<int>>> m;
    int counter = 0, n= str.size();
    
    if(isPalindrome(str)){
        for(int i=1; i<=n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    for(int i=1; i<=n; i++) {
        char c = str[i-1];
        m[c].first++;
        m[c].second.push(i);
    }
    
    
    
    for(auto& k:  m){
        if(k.second.first %2 != 0) counter++;
        if(counter > 1){
            cout << -1 << endl;
            return;
        }
    }
    //Print rearranged position
    
    vector<char> a(n,-3);
    int j=n-1, k=0, i=0;
    
    while(i<n){
        if(m.empty()) break;
        if((m.find(str[i]) != m.end()) && (m[str[i]].first %2 == 0)){
            a[k] = str[i];
            m[str[i]].second.pop();
            a[j] = str[i];
            m[str[i]].second.pop();
            
            k++;
            j--;
            m[str[i]].first -= 2;
            if(m[str[i]].first == 0) m.erase(str[i]);
        }
        i++;
    }
    
    if(!m.empty()){
        char last;
        for(auto &c:m) last = c.first;
        
        for(auto& x:a){
            // if(last.empty()) break;
            if(x == -3) {
                x = last;
            }
        }
    }
    
    for(auto &x:a) cout << x << " ";
    cout << endl;
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

    int t;
    cin >> t;
    while (t--)
        solve();
}
