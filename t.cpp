#include <bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);
int n, d; cin>>n>>d;
vector <vector<string>> v(n,vector<string>(2));
int t[n+1];
for (int i=0; i<n; ++i) cin>>v[i][0]>>v[i][1]>>t[i];
map <pair<string, string>,int> mp;
int ans = 0;
for (int i=0;i<n; ++i) {
	for (int j=i+1; j<n; ++j) {
		if (v[i][0] == v[j][1] && v[i][1] == v[j][0]) {
			if (abs(t[j]-t[i])<=d) {
				if (mp[{v[i][0], v[i][1]}] == 0) {
					++ans;
					mp[{v[i][0], v[i][1]}] == 1;
				}
			} 
		}
	}
}
cout<<ans<<"\n";
return 0;
}