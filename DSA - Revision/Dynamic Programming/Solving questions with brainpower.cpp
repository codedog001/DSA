class Solution {
public:
    vector<long long> dp;
    long long findMostPoints(vector<vector<int>>& a, int index){
        if(index>=a.size()) return 0;
        if(dp[index] != -1) return dp[index];
        
        return dp[index] = max(a[index][0]+findMostPoints(a, index+a[index][1]+1), 0+findMostPoints(a, index+1));
    }    
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size()+1, -1);
        return findMostPoints(questions, 0);
    }
};