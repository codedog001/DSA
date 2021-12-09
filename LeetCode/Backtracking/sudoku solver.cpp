class Solution {
public:
    
    void solveSudoku(vector<vector<char>>& board) {
        fun(board, 0, 0);
    }
    
    bool fun(vector<vector<char>> &a, int row, int col){
        for(int i=0; i<9; i++){
            col = 0;
            for(int j=0; j<9; j++){
                if(a[i][j] != '.') continue;
                for(char c = '1'; c<='9'; c++){
                    if(isValid(a, i, j, c)){
                        a[i][j] = c;
                        if(fun(a, i, j)) return true;
                        //Backtrack
                        a[i][j] = '.';
                    } 
                    
                }
                //Base Case: If no number until 9 returned true, return false
                return false;
            }
        }
        //This will never run
        return true;
    }
    
    bool isValid(vector<vector<char>>& a, int row, int col, char c){
        //Check in current column
        for(int i=0; i<a.size(); i++){
            if(a[i][col] == c) return false;
        }
        
        //Check in current row
        for(int i=0; i<a[i].size(); i++){
            if(a[row][i] == c) return false;
        }
        
        //Check in current sub-square
        int cr = (row/3) *3, cc = (col/3) * 3;
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(a[cr+i][cc+j] == c) return false;
            }
        }
        return true;
    }
};