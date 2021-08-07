#include<iostream>
using namespace std;
 

 class ComplexNumbers {
    // Complete this class
    
    private:
    int real;
    int imag;
    
    public:
    ComplexNumbers(int real, int imag){
        this -> real = real;
        this -> imag = imag;
    }
    
    void print(){
        cout << real << " + i" << imag << endl;
    }
    
	void plus(ComplexNumbers const& refToc2){
        this -> real = real + refToc2.real;
        this -> imag = imag + refToc2.imag;
        
    }
    
    
    
    void multiply(ComplexNumbers const& refToc2){
        int part1 = real * refToc2.real;
        int part2 = (imag * refToc2.real) + (real * refToc2.imag);
        int part3 = imag * refToc2.imag;
        //part3 needs i^2 = -i, i.e. change of sign
        int changedSign = 0 -  part3;
        
        this -> real = part1 + changedSign;
        this -> imag = part2;
    }  
};



int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}



