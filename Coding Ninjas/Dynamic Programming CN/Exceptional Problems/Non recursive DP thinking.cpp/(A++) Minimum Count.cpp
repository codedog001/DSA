#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here -//DONE!!!
    
    int te;
    cin >> te;
    while(te--){
        int n;
        cin>> n;
        int t[n+1] = {0};
        
        t[1] = 1;
        t[2] = 2;
        t[3] = 3;
        t[4] = 1;
        
        for(int i=5; i<=n; i++){
            int sqr = sqrt(i);
            int number = sqr * sqr;
            if(i%number == 0) t[i] = (i/number); //t[i] != 1, try for test case: 8
            else{
                int res = INT_MAX;
                for(int j=sqr; j>=1; j--){
                    int newNumber = j * j;
                    res = min(i/newNumber + t[i%newNumber], res);
                    if(res==2) break; //Can't be lesser than that.
                }
                t[i] = res;
            }
        }
        
        cout << t[n] << endl;
    }
    return 0;
}