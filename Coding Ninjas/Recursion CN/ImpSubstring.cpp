#include<iostream>
using namespace std;

int findSubs(string a, string* output){
    if(a == ""){
        output[0] = "";
        return 1;
    }
    string smallString = a.substr(1);
    int smallStringSize = findSubs(smallString,output);
    
    for(int i=0;i<smallStringSize;i++){
        output[i+ smallStringSize] = a[0] + output[i];
    }
    return 2 * smallStringSize;

}
int main(){
    string input;
    string* output = new string[1000];
    cout<<"Enter the string: "<<endl;
    cin >> input;
    int res = findSubs(input,output);
    cout<<"Output: "<<endl;
    for(int i=0;i<res;i++){
        cout<<output[i]<<endl;
    }
    
}