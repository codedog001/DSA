#include<iostream>
using namespace std;

//Count zeros in array starting from 1st non zero element: 
// 002304 -> Output: 1

//Count number of zeros.
int countZerosForMe(int *b,int size, int totalLength) {

    static int zeroCount=0;
    static bool nzStart=false;

    if(totalLength==0){
        return 0;
    }
    if(totalLength==1){
        if(b[0]==0){
        	return 1;
        }else{
        	return 0;
    	}
    }
    
    else{
        if(size==0){
            return zeroCount;
        }
        if(b[0]!=0){
            nzStart=true;
        }
        if(b[0]==0 && nzStart){
            zeroCount++;
        }
    }
    countZerosForMe(b+1,size-1,totalLength);
    
}

// Return the result.
int countZeros(int *num, int size) {
    int totalLength = size;
    int result = 0;
    // std::cout<<"Size: "<< sizeOfArr << std::endl;    
    
    result = countZerosForMe(num,size,totalLength);
    return result;

}


int main() {
    int n[5];
    cout << "Enter 5 elements: "<<endl;
    for(int i=0;i<5;i++){
        cin >>n[i];
    }
    cout << "No. of zeros in number: " << countZeros(n,5) << endl;
}
