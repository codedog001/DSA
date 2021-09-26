#include <iostream>
using namespace std;
#include<vector>

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,p,x,y;
	    cin >> n;
	    cin >> p;
	    cin >> x;
	    cin >> y;
	    vector<int> a;
	    
	    
	    int timer=0,bin=0;
	    for(int i=0; i<n; i++){
	        cin >> bin;
	        a.push_back(bin);
	    }
	    for(int i=0; i<p-1;i++){
	        if(a[i]==0) timer+=x;
	        else timer+=y;
	    }
	    timer+=y;
	    cout << timer << endl;
	}
}
