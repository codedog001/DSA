// Logic: The logic is to use that color for current node that is not being used by any neighbor, so we only need to track what neighbors are using, and assign a different color to current node.

// I have explained the code in comments below.

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //Graph coloring with 4 colors
        vector<int> result(n+1, 0);
        vector<vector<int>> adjList(n+1);
        
        //Create an adjacency list
        for(auto& edge: paths){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int i=1; i<=n; i++){
            vector<int> color(5, 0);
            vector<int> neighbors = adjList[i];
            
            //Mark colors of neighbors of current node i, that have already been used
            //result[neighbor] stores color that neighbor has already used
            
            for(auto& neighbor: neighbors) color[result[neighbor]] = 1;
            
            //Use the color that has not been used yet
            for(int j=1; j<=4; j++){
                if(color[j] == 0) {
                    result[i] = j;
                    break;
                }
            }
        }
        
        //Size of result is n+1, where index 0 holds information about node 0, but there is no node 0, so
        result.erase(result.begin()+0);
        return result;
    }
};