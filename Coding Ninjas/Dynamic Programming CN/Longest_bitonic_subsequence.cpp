#include<bits/stdc++.h>
using namespace std;
#define ll long long

//0. O(nlogn) Binary Search Method
void lis(vector<ll>& nums, ll* t) {
	int n = nums.size(), curMax = 1;
	vector<int> res;
	res.push_back(nums[0]);
	t[0] = 1;
	for(int i=1; i<n; i++){
		t[i] = 1;
        if(nums[i] > res.back()) {
            res.push_back(nums[i]);
            t[i] = curMax+1;
		}
		else{
			int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
			res[index] = nums[i];
			t[i] = index+1;
		}
        curMax = max(curMax, (int)t[i]);
	}
	return;
}

int main(){
    
    // write your code here
    int to;
    cin >> to;
    while(to--){
        int n; 
        cin >> n;
        vector<ll> a(n);
        
        for(auto& i:a) cin >> i;
        
        //First find longest increasing subsequence ending at that index.
        ll *t = new ll[a.size()]();
        lis(a, t);

        //Now find longest decreasing subsequence starting from that index.
        //That basically means, finding longest increasing sub. at each index
        // of reverse of original array, 
        reverse(a.begin(), a.end());
        
        ll *g = new ll[a.size()]();
        lis(a, g);
        
        reverse(g, g+n);
        ll maxi = INT_MIN;
        for(int i=0; i<n; i++){
            ll ele = t[i] + g[i];
            maxi = max(maxi, ele);
        }
        
        cout << maxi-1 << endl;
    }
}


//1. O(n^2) DP Method.
void lds(vector<ll>& a, ll* t){
    ll n= a.size();
    t[n-1] = 1;
    for(int i=n-1; i>=0; i--){
        t[i] = 1;
        for(int j= n-1; j>i; j--){
            if(a[j] < a[i]){
                int possibleAns = 1 + t[j];
                if(possibleAns > t[i]) t[i] = possibleAns;
            }
            else if(a[j] >= a[i]) continue;
        }
    }
    
    return;
}


void lis(vector<ll>& a, ll* t){
    ll n= a.size();
    
    t[0] = 1;
    for(int i=1; i<n; i++){
        t[i] = 1;
        for(int j= i-1; j>=0; j--){
            if(a[j] >= a[i]) continue;
            else if(a[j] < a[i]){
                int possibleAns = 1 + t[j];
                if(possibleAns > t[i]) t[i] = possibleAns;
            }
        }
    }
    return;
}

int main(){
    
    // write your code here
    int to;
    cin >> to;
    while(to--){
        int n; 
        cin >> n;
        vector<ll> a(n);
        
        for(auto& i:a) cin >> i;
        
        //First find longest increasing subsequence ending at that index.
        ll *t = new ll[a.size()]();
        lis(a, t);
        
        
        //Now find longest decreasing subsequence starting from that index.
        ll *g = new ll[a.size()]();
        lds(a, g);
        
        
        ll maxi = INT_MIN;
        for(int i=0; i<n; i++){
            ll ele = t[i] + g[i];
            maxi = max(maxi, ele);
        }
        
        cout << maxi-1 << endl;
    }
}