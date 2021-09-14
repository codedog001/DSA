int rec(int n, int k){
        if(n==1 && k==1) return 0;
        int len = pow(2,n-1);
        int mid = len/2;
        if(k<=mid) return rec(n-1,k);
        else return !(rec(n-1,k-mid)); 
    }
    int kthGrammar(int n, int k) {
        if(n==1 && k==1) return 0;
        int res = rec(n,k);
        return res;
    }