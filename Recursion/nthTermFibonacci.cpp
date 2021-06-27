#include<iostream>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }
    cout<<"n is " << n <<endl;
    return fib(n-1) + fib(n-2);
}
int main(){
    int n;
    cout <<"Enter the number: " <<endl;
    cin >> n;
    int res = fib(n);
    cout <<res <<endl;
}

