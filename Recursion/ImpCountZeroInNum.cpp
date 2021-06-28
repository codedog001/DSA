#include<iostream>
using namespace std;

//Get Length of number.
int getLen(int num){
    
    if(num==0){
        return 1;
    }

    return 1+getLen(num/10);
    
    
}

//Store number in array.
int* getNumInArr(int num,int size){

    int* p = new int[size];
    
    for(int i=size-1;i>=0;i--){
        int rem = num%10;
        p[i] = rem;
        num=num/10;
    }
    
    // for(int i=0;i<size;i++){
    //     std::cout<<"Array: "<<p[i]<<std::endl;
    // }
    return p;
    
}

//Count number of zeros.
int countZerosForMe(int *b,int size, int totalLength) {
    // Write your code here
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
        countZerosForMe(b+1,size-1,totalLength);
    }
}

// Return the result.
int countZeros(int num) {
  
    int *a =0;
    int sizeOfArr = 0;
    int result = 0;
    
    
    
    sizeOfArr = getLen(num);
    // std::cout<<"Size: "<< sizeOfArr << std::endl;

    a=getNumInArr(num,sizeOfArr);
    
    
    result = countZerosForMe(a,sizeOfArr,sizeOfArr);
    return result;

}


int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
