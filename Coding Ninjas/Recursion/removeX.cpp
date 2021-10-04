#include<iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

int findLen(char* a, int start){
    int len = start;
    while(a[len]!='\0'){
        len++;
    }
    return len;
}


void helpremx(char* a, int start, int end){
    // cout<<"Starts 2"<<endl;
    // cout << "end received is: "<< end<<"last: " << a[end]<<endl;
    if(a[start]=='\0'){
        return;
    }
    if(a[start]=='x'){
        
        int j = start;
        // cout<<"X and " << " end is " << end <<endl;
        cout << "String: "<<a[end+1]<<endl;
        while(j<=end){
            a[j]=a[j+1];
            j++;
        }
        a[end]='\0';
        start--;
        // end--;
    }
    helpremx(a,start+1,end);
}

void removeX(char a[]) {
    // cout<<"Starts"<<endl;
    // Write your code here
	int start = 0;
    int len = findLen(a,start);
    cout << "Length: "<<len<<endl;
    helpremx(a,start,len);
}



int main() {
    char input[100];
    cout<<"Enter String: "<<endl;
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
