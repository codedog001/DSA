#include<bits/stdc++.h>
using namespace std;


int countSubsets(vector<int>& a, int k, int index){
    //Base Case
    int n= a.size();
    if(index == n){
        if(k == 0) return 1;
        else return 0;
    }
    
    int count = 0;
    
    if(k-a[index]>=0) count += countSubsets(a,k-a[index], index+1);
    count+= countSubsets(a,k,index+1);

    
    return count;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n,0);
    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }
	cout << countSubsets(a, k, 0) << endl;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}