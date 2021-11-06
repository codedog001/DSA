#include <iostream>
using namespace std;
typedef long long ll;
#include<unordered_map>

int main() {
    ll t;
    cin >> t;
    while(t--){
        unordered_map<char, int> m;
        string abcd, s;
        cin >> abcd >> s;
        if(s.size() == 1) cout << 0 << endl;
        else{
            for(int i=0; i<abcd.size(); i++){
                m[abcd[i]] = i+1;
            }
            ll res = 0;
            for(ll i=1; i<s.size(); i++){
                ll cur= m[s[i]], prev = m[s[i-1]];
                res += abs(cur - prev);
            }
            cout << res << endl;
        }
    }
    return 0;
}
