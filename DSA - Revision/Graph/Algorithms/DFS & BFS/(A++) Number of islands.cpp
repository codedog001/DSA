a. DFS

class Solution {
public:
    int arr[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m=grid[0].size(), connectedComponent = 0;        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j, grid, n, m);
                    connectedComponent += 1;
                }
            }
        }
        return connectedComponent;
    }
    
    private:
    bool isValid(int newI, int newJ, int n, int m){
        if(newI >= 0 && newJ >= 0 && newI < n && newJ < m) return true;
        return false;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m){
        grid[i][j] = 0;
        for(int k=0; k<4; k++){
            int newI = i + arr[k][0];
            int newJ = j + arr[k][1];
            
            if(isValid(newI, newJ, n, m) && grid[newI][newJ] == '1') dfs(newI, newJ, grid, n, m);
        }
    }
};
b. BFS

class Solution {
public:
    int arr[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    bool isValid(int newI, int newJ, int n, int m){
        if(newI >= 0 && newJ >= 0 && newI < n && newJ < m) return true;
        return false;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m=grid[0].size(), connectedComponent = 0;        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    connectedComponent += 1;
                    
                    q.push({i,j});
                    while(!q.empty()){
                        auto p = q.front();
                        q.pop();
                        
                        //Search in all 4 directions for '1'
                        for(int k=0; k<4; k++){
                            int newI = p.first + arr[k][0];
                            int newJ = p.second + arr[k][1];
                            
                            if(isValid(newI, newJ, n, m) && grid[newI][newJ] == '1'){
                                grid[newI][newJ] = '0';
                                q.push({newI, newJ});
                            }
                        }
                    }
                }
            }
        }
        return connectedComponent;
    }
};