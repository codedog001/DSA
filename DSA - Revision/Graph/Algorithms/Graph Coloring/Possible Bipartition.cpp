We are given edges of graph, if the given is bipartite return true, else return false.

1. DFS:

class Solution {
public:
    vector<int> color;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adjList[n+1];
        color.resize(n+1, -1);
        
        //Create adjacency list
        for(int i=0; i<dislikes.size(); i++){
            int u = dislikes[i][0], v = dislikes[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        //check whether is graph bipartite
        for(int i=1; i<=n; i++){
            if(!isGraphBipartite(i, adjList)) return false; 
        }
        return true;
    }
    
    bool isGraphBipartite(int node, vector<int> adjList[]){
        if(color[node] == -1) color[node] = 1;
        
        vector<int> neighbors = adjList[node];
        for(auto& neighbor: neighbors){
            if(color[neighbor] == -1){ //If neighbor is not visited yet
                color[neighbor] = 1 - color[node];
                if(!isGraphBipartite(neighbor, adjList)) return false;
            }
            else if(color[neighbor] != -1 && color[neighbor] == color[node]) return false;
        }
        return true;
    }
};
2. BFS:

class Solution {
public:
    vector<int> color;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adjList[n+1];
        color.resize(n+1, -1);
        
        //Create adjacency list
        for(int i=0; i<dislikes.size(); i++){
            int u = dislikes[i][0], v = dislikes[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        //check whether is graph bipartite
        for(int i=1; i<=n; i++){
            if(color[i] == -1) {
                if(!isGraphBipartite(i, adjList)) return false; 
            }
        }
        return true;
    }
    
    bool isGraphBipartite(int i, vector<int> adjList[]){
        queue<int> q;
        q.push(i);
        color[i] = 1;

        while(!q.empty()){
            int node = q.front();
            vector<int> t = adjList[node];
            q.pop();
            for(auto& num: t){
                int desiredColor = 1-color[node];
                if(color[num] == -1){
                    color[num] = desiredColor;
                    q.push(num);
                }
                else if(color[num] != desiredColor) return false;
            }
        }
        return true;
    }
};