#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m = 1000000007;
vector<ll> t;

int countStepsToOne(int n){
	if(n<0) return 0;
    if(n==0 || n==1) return 1;
    
    if(t[n] != -1) return t[n];
    int first = 0, second = 0, third = 0;
    first = countStepsToOne(n-1);
    second = countStepsToOne(n-2);
    third = countStepsToOne(n-3);
    
    return t[n] = ((first%m) + (second%m) + (third%m))%m;
}

int main(){
    
    // write your code here
    
    int to;
    cin >> to;
    while(to--){
        ll n;
        t.resize(1000000, -1);
        cin >> n;
        cout << countStepsToOne(n) << endl;
    }
    
    return 0;
}