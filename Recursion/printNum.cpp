#include<iostream>
using namespace std;

void printNumIncOrder(int n){
    if(n==0){
        return;
    }
    printNumIncOrder(n-1);
    cout<< n <<" ";
}

int main(){
    int n;
    cout << "Enter the number: "<<endl;
    cin >> n;

    cout<< "Output: ";
    printNumIncOrder(n);
}