//Uses knapsack 01

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using umi = unordered_map<int, int>;
using umc = unordered_map<char, int>;
using uml = unordered_map<long long, long long>;
using usi = unordered_set<int>;
using usl = unordered_set<long long>;
using usc = unordered_set<char>;
using uss = unordered_set<string>;

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

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

ll firstDigit(ll n){
    string res = to_string(n);
    return res[0]-48;
}

//Custom comparator for priority queue.
class Custom{
    public:
    bool operator () (pii &a, pii &b){
        
        // cout << "Pair a: <" << a.first << "," << a.second << "> b: <" << b.first << "," << b.second << "> ";
        //Compare frequency 
        if(a.second > b.second) {
            // cout << "true" << endl;
            return true;
        }
        
        return false;
    }
};

bool isPalindrome(string& s){
    ll i=0, j=s.size()-1;
    while(i<=j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

bool doubleIsInt(double trouble) {
   double absolute = abs( trouble );
   return absolute == floor(absolute);
}

bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

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

//Returns max. element of vector along with index
pll getMax(vector<ll>& a){

    vector<ll>::iterator it;
    it = max_element(a.begin(), a.end());
    
    return {*it, it-a.begin()};
}

//Returns min. element of vector along with index
pll getMin(vector<ll>& a){

    vector<ll>::iterator it;
    it = min_element(a.begin(), a.end());
    
    return {*it, it-a.begin()};
}

bool numIsOdd(ll n){
    if(n&1==1) return true;
    return false;
}
    
void stringPermutation(string a, int l, int r, vector<string>& v)
{
    // Base case
    if (l == r)
       v.pb(a);
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            stringPermutation(a, l+1, r, v);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}

//1. Bottom Up approach (Dynamic Programming)
bool isSubsetSum(int n, int arr[], int sum){
        bool t[n+1][sum+1];
        
        //Initialization
        for(int i=1; i<sum+1; i++) t[0][i] = false;
        for(int j=0; j<n+1; j++) t[j][0] = true;
        
        //Knapsack code
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }


    bool helper(ll n, ll arr[], int sum, vector<vector<ll>>& t){
         //Base case
        if(sum==0) return 1;
        if(n<=0) return 0;
        
        if(t[n][sum] != -1) return t[n][sum];
        //Choice diagram
        if(arr[n-1] <= sum){
            t[n][sum] = helper(n-1, arr, sum-arr[n-1],t) || helper(n-1, arr, sum, t);
            return t[n][sum];
        }
        else {
            t[n][sum] = helper(n-1, arr, sum,t);
            return t[n][sum];
        }
    }

    bool isSubsetSum(ll n, ll arr[], ll sum){
       vector<vector<ll>> t(n+1, vector<ll>(sum+1, -1));
       return helper(n,arr,sum,t);
    }

void solve() {

    // Effort might not always be fruitful, but it's never wasted.
    ll n, sum =0; 
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++){
        ll x; 
        cin >> x;
        sum += x;
        a[i] = x;
    }
    
    ll target = sum/2;
    if(isSubsetSum(n, a, target)) cout << "YES" << endl;
    else cout << "NO" << endl;
        
    
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

    int t=-1;
    // cin >> t;
    // while (t--)
        solve();
}