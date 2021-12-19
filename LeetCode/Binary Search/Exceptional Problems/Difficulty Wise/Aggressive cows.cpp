#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canAllCowsBePlacedAtMidDistance(vector<ll>& a, ll distanceToMaintain, ll c, ll n){
    ll currentDistance = 0;
    c--; //Placed first cow in first barn, now place rest cows
    for(int i=1; i<n; i++){
        currentDistance += a[i]-a[i-1];
        
        if(currentDistance >= distanceToMaintain){
            c--;
            currentDistance = 0;
        }
        
        //If all cows can be arranged at a distance of distanceToMaintain, return true.
        if(c<=0) return true;
    }
    //All cows could not be placed at distanceToMaintain, so return false.
    return false;
}

void solve(){
    ll n, c,res = 1;
    cin >> n >> c;
    vector<ll> a(n,0);
    for(auto &i:a) cin >> i;
    
    sort(a.begin(), a.end());
    ll start = 1; //Min. distance b/w two barns could be 1.
    ll end = a[n-1] - a[0]; //Max distance b/w two barns could be (pos. of last barn) - (pos. of first barn)
    
    //Using binary search, we will find max distance b/w min and max possible distance to arrange c cows.
    while(start<=end){
        ll mid = start + (end-start)/2;
        if(canAllCowsBePlacedAtMidDistance(a,mid,c,n)){
            res = mid;
            
            //If current distance was possible try increasing this distance.
            start = mid+1;
        }
        //This distance was not possible so reduce this distance.
        else end = mid-1;
    }
    cout << res << endl;
}

int main(){
    // write your code
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}