//Two functions need memoization

3. Optimized Memoized:
We need to memoize isPalindrome too, otherwise result will be TLE.

class Solution {    
public:
    vector<vector<int>> pal;
    vector<vector<int>> t;
    
   bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (pal[i][j] != -1) return pal[i][j];
		if (s[i] == s[j]) return pal[i][j] = isPalindrome(s, i + 1, j - 1);
		return pal[i][j] = false;
	}
    
    int solve(string &s, int i, int j){
        //Base Case
        if(i>=j) return t[i][j] = 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        
        if(isPalindrome(s,i,j)) return t[i][j] = 0;
        
        int res = INT_MAX;
        
        //Move K
        for(int k=i; k<=j-1; k++){
            if(isPalindrome(s,i,k)) res = min(res, 1 + solve(s,k+1,j));
            // int temp = solve(s, i, k) + solve(s, k+1, j) + 1;
            // res = min(res, temp);
        }
        
        return t[i][j] = res;
    }
    int minCut(string s) {
        int i=0, j=s.size()-1, n= s.size();
		pal.resize(s.size(),vector<int> (s.size(),-1));
        t.resize(s.size(),vector<int> (s.size(),-1));
        return solve(s,i,j);
    }
};

1. Recursive: (TLE)

class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s, int i, int j){
        //Base Case
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        
        int res = INT_MAX;
        
        //Move K
        for(int k=i; k<=j-1; k++){
            int temp = solve(s, i, k) + solve(s, k+1, j) + 1;
            res = min(res, temp);
        }
        
        return res;
    }
    int minCut(string s) {
        int i=0, j=s.size()-1;
        return solve(s,i,j);
    }
};
2. Memoized: (TLE)

bool isPalindrome(string &s, int i, int j){
        if(i==j || i>j) return true;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j, vector<vector<int>> &t){
        //Base Case
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        int res = INT_MAX;
        
        //Move K
        for(int k=i; k<=j-1; k++){
            int temp = solve(s, i, k, t) + solve(s, k+1, j, t) + 1;
            res = min(res, temp);
        }
        
        return t[i][j] = res;
    }
    int minCut(string s) {
        int i=0, j=s.size()-1, n= s.size();
        
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        return solve(s,i,j, t);
    }
