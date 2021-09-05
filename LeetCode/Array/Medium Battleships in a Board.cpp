// Count first head of each battleship.
// Checking first head: If there is no 'X' in left or top of current 'X', then it is head of the ship.

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i=0;i<board.size(); i++){
            for( int j=0; j<board[i].size(); j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(i>0 && board[i-1][j] == 'X'){
                    continue;
                }
                if(j>0 && board[i][j-1] == 'X'){
                    continue;
                }
                count++;
                
            }
        }
        
        return count;
        
    }
};