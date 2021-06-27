#include<iostream>
using namespace std;

int power(int x,int n){
    if(n==1){
        return x;
    }
    int smallAns = power(x,n-1);
    return x*smallAns;
}

int main(){
    int res = power(4,3);
    cout<<"RESULT: "<<res<<endl;

}