#include<iostream>
using namespace std;

bool checkNumber(int a[], int n, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    
    if(n==0){
        return false;
    }if(a[0]==x){
        return true;
    }
    else checkNumber(a+1,n-1,x);
    
    

    
    
}

int main(){
    int n;
    cin >> n;
  
    int *a = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(a, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}


