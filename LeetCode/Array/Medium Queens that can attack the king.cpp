class Solution {
public:
    
    vector<int> makeVec(int a, int b){
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        
        return v;
    }
     
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        char grid[8][8];
        for (auto &queen : queens) {
            grid[queen[0]][queen[1]] = 'Q';
        }
        
        // Go down
        for (int i = king[0]; i < 8; i++) {
            if (grid[i][king[1]] == 'Q') {
                res.push_back(makeVec(i, king[1]));
                break;
            }
        }
        
        // Go up
        for (int i = king[0]; i >= 0; i--) {
            if (grid[i][king[1]] == 'Q') {
                res.push_back(makeVec(i, king[1]));
                break;
            }
        }
        
        // Go right
        for (int i = king[1]; i < 8; i++) {
            if (grid[king[0]][i] == 'Q') {
                res.push_back(makeVec(king[0], i));
                break;
            }
        }
        
        // Go left
        for (int i = king[1]; i >= 0; i--) {
            if (grid[king[0]][i] == 'Q') {
                res.push_back(makeVec(king[0], i));
                break;
            }
        }
        
        // Up left diagonal
        for (int i = king[0], j = king[1]; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') {
                res.push_back(makeVec(i,j));
                break;
            }
        }
        
        // Up right diagonal
        for (int i = king[0], j = king[1]; i >= 0 && j < 8; i--, j++) {
            if (grid[i][j] == 'Q') {
                res.push_back(makeVec(i,j));
                break;
            }
        }
        
        // Down left diagonal
        for (int i = king[0], j = king[1]; i < 8 && j >= 0; i++, j--) {
            if (grid[i][j] == 'Q') {
                res.push_back(makeVec(i,j));
                break;
            }
        }
        
        // Down right diagonal
        for (int i = king[0], j = king[1]; i < 8 && j < 8; i++, j++) {
            if (grid[i][j] == 'Q') {
                res.push_back(makeVec(i,j));
                break;
            }
        }
        
        return res;
    
    }
    
};