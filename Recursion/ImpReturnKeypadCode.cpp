#include <iostream>
#include <string>
using namespace std;


string * alpha {new string[10]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}};
static int lenArrayA = 0;

void populateArray(string * a, int workOnNum, int lenOfWorkOnNum){
	int j=0;
    int i=0;
    int countOfThisLetter = lenArrayA/lenOfWorkOnNum;
    
    for(i=0;i<lenArrayA;i++){
        if(countOfThisLetter <= 0){
            j++;
            countOfThisLetter = lenArrayA/lenOfWorkOnNum;
        }
        a[i] += alpha[workOnNum][j];
        countOfThisLetter--;
    }
}


void copyArr(int workOnNum, string a[]){
    //Purpose: Make copy of array depending on work.
     int i=0,j=0,lenOfWorkOnNum=0,lengthOfArray=0;
    
    lenOfWorkOnNum = alpha[workOnNum].length();
    
    
    int thisIndex = 0;

    
    for(i=0;i<=lenOfWorkOnNum;i++){
        for(j=0;j<lenArrayA;j++){
            a[thisIndex++] = a[j];
        }
    }
    
    lenArrayA*=lenOfWorkOnNum;
    populateArray(a,workOnNum,lenOfWorkOnNum);   
}

void hkey(int num, string * a){
    
    if(num==0){
        a[0] = "";
        lenArrayA++;
        return;
    }
    
    int workOnNum = num%10;
    hkey(num/10,a);
    copyArr(workOnNum,a);
    
}

int keypad(int num, string * a){
    hkey(num,a);
    int i=0;
    return lenArrayA;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
