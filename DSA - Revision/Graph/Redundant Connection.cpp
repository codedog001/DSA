class Solution {
public:
    vector<vector<int>> result;
    vector<int> visited;
    int n = 0;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int> undirAdjList[n+1];
        visited.resize(n+1, 0);
        
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            undirAdjList[u].push_back(v);
            undirAdjList[v].push_back(u);
        }
        
        int parent  = -1, source = 1;
        bool isCycle = false;
        detectCycleDFS(source, parent, undirAdjList, isCycle);
        cout << "size: " <<  result.size() << endl;
        for(auto& t:result){
            cout << t[0] << " - " << t[1] << endl;
        }
        return {1,3};
    }
    
    private:
    void detectCycleDFS(int node, int parent, vector<int> undirAdjList[], bool& isCycle){
        visited[node] = 1;
        
        vector<int> neighbors = undirAdjList[node];
        for(auto & neighbor: neighbors){
            if(visited[neighbor] == 0) {
                detectCycleDFS(neighbor, node, undirAdjList, isCycle);
                if(isCycle && parent != -1){
                    vector<int> temp = {min(node, neighbor), max(node, neighbor)};
                    result.push_back(temp);
                }
            }
            else if(visited[neighbor] == 1 && parent != neighbor){
                vector<int> temp = {min(node, neighbor), max(node, neighbor)};
                result.push_back(temp);
                isCycle = true;
            }
        }
    }
};