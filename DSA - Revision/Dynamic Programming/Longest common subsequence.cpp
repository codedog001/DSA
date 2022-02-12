class Solution {
public:
    vector<vector<int>> t;
    int longestCommonSubsequence(string a, string b) {
        int x = a.size(), y = b.size();
        t.resize(x+2, vector<int>(y+2, -1));
        return helper(a, b, x, y);
    }
    
    int helper(string& a, string& b, int x, int y){
        if(x == 0 || y==0) return 0;
        if(t[x][y] != -1) return t[x][y];
        if(a[x-1] == b[y-1]){
            return t[x][y] = 1 + helper(a, b, x-1, y-1);
        }
        else{
            return t[x][y] = max(helper(a, b, x, y-1), helper(a, b, x-1, y));
        }
    }
};