//1. Recursive
    bool isPowerOfTwo(int n) {
            return n > 0 && (n == 1 || (n%2 == 0 && isPowerOfTwo(n/2)));
    }

//2. Iterative
    bool isPowerOfTwo(int n) {
        if(n<= 0)  return false;
        while(n%2==0){
           n=n/2;
        }
        return n==1;
    }
	
	//3. Look Up table - O(1) time complexity
    bool isPowerOfTwo(int n) {
          unordered_set<int> m ({1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608,16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824});
            
        if(m.find(n)!=m.end()) return true;
           
        return false;
    }
	
	//4. n&(n-1) 
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
    }