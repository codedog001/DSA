#include<iostream>
using namespace std;

int sum(int a[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    
    if(n==0){
        return 0;
    }
    int sumarr = a[0];
    // std::cout << sumarr << " + " << std::endl;
    sumarr = sumarr + sum(a+1,n-1);
    
    return sumarr;
    
    
    
    

}


int main(){
    int n,a[10];
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << sum(a, n) << endl;
}


