#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print the changed string.


int findLen(char* a){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    
    return i;
}

void helpPairStar(char* a, int start, int len){
    
    cout<<"RUNS, a[start] is: "<< a[start] <<endl;
    bool isShift=false;
    
    if(a[start+1]=='\0'){
        return;
    }
    if(a[start]==a[start+1]){
        
        cout<<"Before adding * string is: " <<a <<endl;

        int j=len;
        while(j>start){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]='*';
        cout<<"After adding * string is: " <<a <<endl;
        isShift=true;
        len++;
    }
    if(isShift){
        helpPairStar(a,start+2,len);
    }else{
        helpPairStar(a,start+1,len);
    }
}

void pairStar(char input[]) {
    // Write your code here
    cout<<"BEGINS"<<endl;
    int start=0;
    int len = findLen(input);
    std::cout<<"Len is: " << len <<std::endl;
	helpPairStar(input,start,len);
}



int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
