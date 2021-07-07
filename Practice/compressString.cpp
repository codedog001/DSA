#include <iostream>
#include <cstring>
using namespace std;

static char * finalarr {new char[9999]{0}};

void helpstringCompression(char *a) {
    // Write your code here
    //Using Recursion:
    
    static int m=0;
    int counter =0;
    int len=0;
    static bool once = true;
    
    if(once){
        len = strlen(a);
    }
    
    if(a[0]=='\0'){
        // finalarr[m]='\0';
        cout<<a<<endl;
        strcpy(a,finalarr);
        cout<<a<<endl;
        return;
    }
    if(a[1]!=a[0]){
        
        finalarr[m] = a[0];
        m++;
        helpstringCompression(a+1);
    }

    
    else{
        int i=0;
        if(a[0]==a[1]){
            while(a[0]==a[i]){
                counter++;
				// cout<< "a[0] is: " << a[0] << " and counter is: " << counter <<endl;
                i++;
            }
            finalarr[m++] = a[0];
            finalarr[m++] = (char)counter+48;
            helpstringCompression(a+counter);
        }
    }
    
}
void stringCompression(char* a){
        helpstringCompression(a);
        cout<<"HERE"<<endl;
        strcpy(a,finalarr);
        cout<<a;
        return;
    }

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    stringCompression(str);
    cout << str;
}