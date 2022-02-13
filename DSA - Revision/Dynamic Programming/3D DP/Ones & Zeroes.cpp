class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(m+2, vector<vector<int>>(n+2, vector<int>(strs.size()+2, -1)));
        return helper(strs, 0, m, n);
    }
    
    int helper(vector<string>& strs, int index, int m , int n){
        if(index == strs.size()) return 0;
        if(m<=0 && n<=0) return 0;
        
		if(dp[m][n][index] != -1) return dp[m][n][index];
        auto zeroesAndOnes = countZeroesAndOnes(strs[index]);
        int zeroes = zeroesAndOnes.first, ones = zeroesAndOnes.second;
        
        if(zeroes <= m && ones <= n){
            //Choice to select this string or skip it
            dp[m][n][index] = max(1 + helper(strs, index + 1, m-zeroes, n-ones), helper(strs, index + 1, m, n));
            return dp[m][n][index];
        }
		
		//No choice: Skip this string
        else return dp[m][n][index] = helper(strs, index+1, m, n);
    }
    
    pair<int, int> countZeroesAndOnes(string& str){
        int zeroes = 0, ones = 0;
        for(auto& c:str){
            if(c=='0') zeroes+=1;
            else ones += 1;
        }
        return {zeroes, ones};
    }
};