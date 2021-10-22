#include<iostream>
using namespace std;

int countDig(int n){
    if(n==0){
        return 0;
    }
    int smallAns = countDig(n/10);
    return 1+smallAns;
}

int main(){
    int n;
    cout << "Enter number"<<endl;
    cin >> n;
    int digits = countDig(n);
    cout<<digits<<" Digits"<<endl;
}