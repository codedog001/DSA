// Use this test case to understand why custom queue is used.
4
1700 1900 2000 2100
2200 2000 2100 2299

#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
typedef pair<int, int> ppi;


class Custom{
    public:
    bool operator () (ppi &a, ppi &b){
        
        // cout << "Pair a: <" << a.first << "," << a.second << "> b: <" << b.first << "," << b.second << "> ";
        //Compare frequency 
        if(a.second > b.second) {
            // cout << "true" << endl;
            return true;
        }
        
        return false;
    }
};

using namespace std;
int main() {

	// Write your code here
    int n;
    cin >> n;
    vector<int> a(n,0);
    vector<int> d(n,0);
    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }
    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        d[i] = x;
    }
    
    vector<pair<int, int>> v;
    
    for(int i=0; i<n; i++){
        pair<int, int> t = {a[i], d[i]};
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    priority_queue<ppi, vector<ppi>, Custom> s;
    s.push(v[0]);
    int res = 1;
    
    for(int i=1; i<v.size(); i++){
        pair<int, int> t = v[i];
        while(s.size() && t.first > s.top().second){
            s.pop();
        }
        s.push(t);
        int temp = s.size();
        res = max(temp, res);
    }
    cout<< res;
}