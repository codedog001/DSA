#include<bits/stdc++.h>
using namespace std;

string str = "CODINGNINJA";

bool dfs(vector<vector<char>> &a, int row, int col, vector<vector<bool>>& visited, int n, int m, int strptr, stack<pair<int, int>>& st, int lr, int lc){
    if(strptr >= str.size()) return true;
    //Search for ODINGNINJA in 8 directions letter by letter.
    
    int fr = INT_MIN, fc = INT_MIN;
    cout << "SEARCHING FOR: " << str[strptr] << endl<< endl;
    
    //Upward
    	if(row>0 && !visited[row-1][col] && a[row-1][col] == str[strptr] && !(lr == row-1 && lc == col)){
            fr = row-1;
            fc = col;
        }
    //up right
    	else if(row >0 && col+1<m && !visited[row-1][col+1]  && a[row-1][col+1] == str[strptr] && !(lr == row-1 && lc == col+1)  ){
            fr = row-1;
            fc = col+1;
        }
    //up left
        else if(row > 0 &&  col >0 && !visited[row-1][col-1] && a[row-1][col-1] == str[strptr] &&  !(lr == row-1 && lc == col-1)){
            fr = row-1;
            fc = col-1;
        }
    //right
    	else if(col+1<m && !visited[row][col+1] &&  a[row][col+1] == str[strptr] && !(lr == row && lc== col+1)){
            fr = row;
            fc = col+1;
        }
    //left
    	else if(col>0 && !visited[row][col-1] && a[row][col-1] == str[strptr] && !(lr == row && lc==col-1)){
            fr = row;
            fc = col-1;
        }
    //down right
    	else if(row+1<n && col+1<m && !visited[row+1][col+1] && a[row+1][col+1] == str[strptr] &&  !(lr == row+1 && lc == col+1)  ){
            fr = row+1;
            fc = col+1;
        }
    //down 
    	else if(row+1<n && !visited[row+1][col] && a[row+1][col] == str[strptr] && !(lr == row+1 && lc == col)){  
            fr = row+1;
            fc = col;
        }
    //down left
    	else if(row+1<n  && col>0  && !visited[row+1][col-1] && a[row+1][col-1] == str[strptr] && !(lr == row+1 && lc == col-1)  ){
            fr = row+1;
            fc = col-1;
        }
    
    if(fr!=INT_MIN){
        // cout<< "found: " << a[fr][fc] << " on row: " << row << " col: " << col << " fr: "  << fr << " fc: " << fc <<endl;
        st.push({row,col});
        
        strptr+=1;
        visited[fr][fc] = true;
        dfs(a, fr, fc, visited, n, m, strptr, st, lr, lc);
    }
    else if(fr == INT_MIN){
        //Backtrack
        // strptr-=1;
        //temp false
        // cout <<"STRPTR is: " << strptr << endl;
        // cout << "Searching for: " << s[strptr] <<endl;
        pair<int, int> t = st.top();
        strptr-=1;
        lr = row;
        lc = col;
        // cout <<"strptr: " << strptr << " cur row: " << row << " col: " << col << " popped row: " << t.first << " col: "<< t.second << endl;
		visited[row][col] = false;
        st.pop();
        dfs(a,t.first, t.second, visited, n, m, strptr, st, lr, lc);
    }
     
}


bool helper(vector<vector<char>> &a, int n, int m) {
    // Find 'c'.
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a[i].size(); j++){
            char d= a[i][j];
            if(d=='C') {
                vector<vector<bool>> visited(n, vector<bool>(m,false));
                // cout << "RUNS" << endl;
                visited[i][j] = true;
            	stack<pair<int, int>> st;
                if(dfs(a, i, j, visited, n, m, 1, st, -1,-1)) {
                    // cout << "stack size is: " << st.size() << endl;
                    return true;
                }
            }
        }
    }
    return false;
    
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    // return true;
    return helper(board, n, m);
    
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
    return 0;
}