#include<bits/stdc++.h>
using namespace std;

int b[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool isValid(int x, int y, int n,int  m){
    if(x>=0 && y>=0 && x<n && y<m) return true;
    return false;
}

bool isAdjacent(int cr, int cc, int ro, int co){
    
    int ar = abs(cr-ro);
    int ac = abs(cc-co);
    int res = ar ^ ac;

    if(ar <= 1 && ac <= 1 && res != 0) return true;
    return false;
}

bool dfs(vector<vector<char>> &a, int row, int col, vector<vector<bool>>& visited, int n, int m, int sameChar, int ro, int co){
    if(sameChar >= 4 && isAdjacent(row, col, ro, co)) return true;
    visited[row][col] = true;
    
    for(int i=0; i<4; i++){
        int newX = row + b[i][0];
        int newY = col + b[i][1];
        
        if(isValid(newX,newY,n,m) && a[newX][newY]==a[row][col] && !visited[newX][newY]){
            // if(ro==0 && co==0) cout << newX << " " << newY << " S: " << sameChar << endl;
            if(dfs(a,newX, newY, visited, n,m, sameChar+1, ro, co)) return true;
        }
    }
    
    visited[row][col] = false;
    return false;
}

bool hasCycle(vector<vector<char>> &a, int n, int m) {
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool found = false;
    int sameChar = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sameChar =1;
            //i and j at last are point of chain starting
            found = dfs(a, i, j, visited, n, m, sameChar, i, j);
            if(found)break;
        }
        if(found) break;
    }
    
    return found;
}