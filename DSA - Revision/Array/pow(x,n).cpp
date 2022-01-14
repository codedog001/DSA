class Solution {
public:
    
    void powerHelper(double x, long long n, double& res){
        if(n==0) return;
        
        if(n%2 == 0){
            x = x * x;
            powerHelper(x, n/2, res);
        }else{
            res = res * x;
            powerHelper(x, n-1, res);
        }
    }
    
    double myPow(double x, int n) {
        long long p = abs(n);
        
        double res = 1;
        powerHelper(x, p, res);
        if(n < 0) res = (double) 1.0/ res;
        return res;
    }
};