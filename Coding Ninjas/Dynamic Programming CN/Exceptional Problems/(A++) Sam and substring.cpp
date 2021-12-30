//Hackerrank Problem
int helper(string& s, int size, long long & ans){
    if(size == 0) return s[0]-'0';
    
    if(size<0) return 0;
    long long sum = helper(s, size-1, ans);
    int digit = s[size] - '0';
    
    long long res = ((sum*10) + (digit*(size+1))) % mod;
    ans = (ans+res)%mod;
    
    return res%mod;
}


int substrings(string s) {
    int n= s.size();
    long long ans = s[0]-'0';
    helper(s, n-1, ans);
    return ans;
}