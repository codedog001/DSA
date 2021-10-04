#include<iostream>
using namespace std;

int lastIndex(int a[], int n, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    
    static int index= n-1;
    if(n==0){
        return -1;
    }
    if(a[n-1]==x){
        return index;
    }
    else{
        index--;
        lastIndex(a,n-1,x);
    }
    

}

#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}


