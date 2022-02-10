Logic: Place Queen on safe position and call DFS on next row, when call ends backtrack, i.e. remove Queen from that position. That's it. I have added comments for better understanding.

class Solution {
public:    
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        
        //Create Board
        vector<string> originalBoard;
        string s = "";
        
        for(int i=0; i<n; i++) s += '.';
        for(int i=0; i<n; i++) originalBoard.push_back(s);
        
        //Call helper to place Queens
        placeQueens(0, n, originalBoard);
        return result;
    }
    
    void placeQueens(int row, int n, vector<string>& board){
        if(row == n){
            result.push_back(board);
            return;
        }
        
        for(int j=0; j<n; j++){
            if(isSafeForQueen(row, j, n, board)){
                
                //Place Queen at this position
                board[row][j] = 'Q';
                placeQueens(row+1, n, board);
                
                //Backtrack: Remove Queen from this position
                board[row][j] = '.';
            }
        }
        return;
    }
    
    bool isSafeForQueen(int row, int col, int n, vector<string>& board){
        //Check up
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }
        
        //Check left diag
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        
        //Check right diag
        for(int i=row-1, j=col+1; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};