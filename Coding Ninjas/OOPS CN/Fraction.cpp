#include<iostream>
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;

    public:
    Fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;   
    }

    //Is function k pas object ka address this keyword me stored hoga
    //this ko hata bhi skte hai, kyuki argument me numerator ya denominator nai hai to implicitly numerator ka mtlb this -> numerator hai and same for den.

    void print(){
        cout << numerator << "/" << denominator << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(numerator,denominator);
        for(int i=1; i<=j; i++){
            if(numerator%i==0 && denominator%i == 0){
                gcd = i;
            }
        }

        numerator = numerator/gcd;
        denominator = denominator/gcd;
    }

    //Now for add function we need to pass only one fraction, kyuki jab hum f1.add() call krenge
    // tb hmare function k this keyword f1 ka address a jaega, to bs f2 ko pass krna hoga.
    //Agar ham this nai likhenge to koi difference nai aega, kyuki there is no other variable named numerator or den. in fun.
    //numerator will be interpreted as this-> numerator only (and it will numerator of f1), and for num of f2 we will use f2.numerator and similarly for den.
    //Also we want ki f2 should be passed through reference and const because we don't want this function (refTof2) to change value of f2.
    //refTof2 can only read this value, can't change it.
    
    void add(Fraction const& refTof2){
        int lcm = denominator * refTof2.denominator;
        int x = lcm / denominator;
        int y = lcm / refTof2.denominator;

        int num = (x * numerator) + (y * refTof2.numerator);

        numerator = num;
        denominator = lcm;

        //Now we need to simplify this fraction
        //It can be done by dividing the num. and den. by HCF.
        simplify(); //this->simplify();
    }

};