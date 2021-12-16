#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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
using maxPqll = priority_queue<ll>;

// Vectors
#define pb push_back
#define all(a) a.begin(), a.end()
#define llmax 1e10

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

bool customSort(pll& a, pll& b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else if(a.first == b.first){
        return b.second > a.second;
    }
}

ll strToNum(string& a){
    stringstream str(a);
    ll num;
    str >> num;
    return num;
}

void generateLuckyNum(ll t, vector<ll>& v){
    if(t>llmax) return;
    v.pb(t);
    generateLuckyNum(t*10+4, v);
    generateLuckyNum(t*10+7, v);
}

string to_bin(long long x)
{
    if(x == 0)
        return "";
    else
    {
        string s = to_bin(x / 2);
        s.push_back(char('0' + x % 2));
        return s;
    }
}

void solve() {
    
    // Effort might not always be fruitful, but it's never wasted.
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    ll num, den;
    if((a/b) == (c/d)){
        cout << "0/1" <<endl;
        return;
    }
    else if((a/b)< (c/d)){
        num = (b*c) - (a*d); // ratio of unoccupied screen
        den = b*c;
    }
    else{
        num = (a*d) - (b*c);
        den = (a*d);
    }
    ll g = __gcd(num, den);
    cout << num/g << "/" << den/g << endl;
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