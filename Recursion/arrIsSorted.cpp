#include<iostream>
using namespace std;

bool isSorted(int a[], int size){
    if(size==0||size==1){
        return true;
    }
    
    if(a[0]<a[1]){
        isSorted(a+1,size-1);
    }else{
        return false;
    }


}


int main(){
    int a[5];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<5;i++){
        cin >> a[i];
    }
    bool res = isSorted(a,5);
    cout << "result: ";
    res? cout << "true": cout << "false" << endl;
}