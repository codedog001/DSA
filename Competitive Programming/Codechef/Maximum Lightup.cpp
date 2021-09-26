#include <iostream>
using namespace std;

int main() {
    
	long t;
	cin >> t;
	
	while (t--)
	{
	    long long P,a,b,c,x,y;
	    
	    cin>>P>>a>>b>>c>>x>>y;
	    
	    long long  anar = x * a + b;
	    long long chakri = y * a + c;
	    
	    long long ans = 0;
	    
	    if (anar < chakri)
	    {
	        ans = anar;
	    }
	    else
	    {
	        ans = chakri;
	    }
	    
	    cout << P / ans <<endl;

	       

	}
	return 0;
}