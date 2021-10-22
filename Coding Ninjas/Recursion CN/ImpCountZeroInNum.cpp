#include<iostream>
using namespace std;


//Remember: Num always starts from first nonZero digit.

int countZeros(int n) {
    // Write your code here
	int isZero =0;
	if(n<=9){
        if(n==0){
            return 1;
        }
        return 0;
    }
    if(n%10==0){
        isZero=1;
    }
    
    return isZero+countZeros(n/10);
}


int main() {
    int n;
    cout<<"Enter Number: " << endl;
    cin >> n;
    cout<<"Number Entered: "<<n<<endl;
    cout << "No. of Zeros: "<< countZeros(n) << endl;
}
