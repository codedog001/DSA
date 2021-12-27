//In coding ninjas: DP - 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m= 1e9+7;

ll findWaysToDecode(string& s, ll size, ll* t){
    if(size == 1 || size==0 ) return 1;
    
    if(t[size] != 0) return t[size];
    
    ll count = 0;
    // 1 digit
    
    if(s[size-1] != '0'){
        count += findWaysToDecode(s, size-1, t)%m;
    }
    
    // 2 digit
    if(size > 1 && s[size-1] != '0' && s[size-2] != '0'){
        int num = 0;
        num = (s[size-2] - '0') *10;
        num += s[size-1] - '0';
        if(num >= 1 && num <= 26){
            count += findWaysToDecode(s, size-2, t)%m;
            count %= m;
        }
    }
    t[size] = count;
    return count;
}

int main(){
    
    // write your code here
    ll to; 
    cin >> to;
    while(to--){
        string s;
        cin >> s;
        ll* temp = new ll[s.size() + 1]();
        ll res = findWaysToDecode(s, s.size(), temp);
        cout << res << endl;
    }
    // return 0;
}