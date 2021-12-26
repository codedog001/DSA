//Coding Ninjas: https://classroom.codingninjas.com/app/classroom/me/8017/content/121817/offering/1423813/problem/7217
//Problem: Murder

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll merge(vector<ll>& a, ll start, ll mid, ll end){
    ll i=start, j= mid, k = 0, n= a.size(), res = 0;
    
    vector<ll> temp(end-start+1,0);
    while(i < mid && j<=end){
        if(a[i] < a[j]){
            temp[k] = a[i];
            res += ((end-j+1) * a[i]);
            i++;
            k++;
        }else{
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    
    while(i<mid){
		temp[k] = a[i];
        i++;
        k++;
    }
    
    while(j<=end){
        temp[k] = a[j];
        k++;
        j++;
    }
    
    for(ll i=start, k=0; i<=end; i++,k++) a[i] = temp[k];
    return res;
}

ll mergeSort(vector<ll>&a, ll start, ll end){
    if(start<end){
        ll mid = start + (end-start)/2;
        ll c1 = mergeSort(a,start, mid);
        ll c2 = mergeSort(a, mid+1, end);
        ll c3 = merge(a, start, mid+1, end);
        
        return c1+c2+c3;
    }
    return 0;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i:a) cin >> i;
    
    ll res = mergeSort(a,0,n-1);
    cout << res << endl;
}

int main(){
    // write your code
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}