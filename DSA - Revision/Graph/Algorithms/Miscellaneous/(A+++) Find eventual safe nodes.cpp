A dry run of solution below on pen & paper would make the solution easier to understand.
This is not kosaraju's opposite, if a node not involved in strongly connected component leads to a strongly connected component then also it is not a safe node, but according to kosaraju that node will be an individual strongly connected component, hence it is not opposite of kosaraju.

1. Transpose and remove terminal Nodes:
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
		
        //Step 1. Transpose the graph
        vector<int> transposeGraph[n];
        for(int i=0; i<n; i++){
            vector<int> neighbors = graph[i];
            for(auto& neighbor: neighbors){
                transposeGraph[neighbor].push_back(i);
            }
        }
        
        //Step 2. Find in degree of nodes
        vector<int> inDegree(n, 0), result;
        for(int i=0; i<n; i++){
            vector<int> neighbors = transposeGraph[i];
            for(auto& neighbor: neighbors){
                inDegree[neighbor] += 1;
            }
        }
        
        //Step 3. Push nodes into result whose path leads to terminal nodes, in other words, nodes which are not part of a cycle themselves and also not leading to a cycle.
        
        //Push nodes having indegree = 0 in queue
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        //Remove terminal nodes from graph, and reduce indegree of nodes that were connected to terminal nodes.
        while(!q.empty()){
            int node = q.front();
            result.push_back(node);
            q.pop();
            
            vector<int> neighbors = transposeGraph[node];
            for(auto& neighbor: neighbors){
                inDegree[neighbor] -= 1;
                if(inDegree[neighbor] == 0) q.push(neighbor);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

2. DFS:

#define vvi vector<vector<int>>
#define usi unordered_set<int>

class Solution {
public:
    usi cycleNodes, safeNodes;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result, visited(n,0);
        
        for(int i=0; i<n; i++){
            if(dfs(i,graph, visited)) result.push_back(i);
        }
        return result;
    }
    
    bool dfs(int node, vvi& graph, vector<int>& visited){
        if(safeNodes.find(node) != safeNodes.end()) return true;
        if(cycleNodes.find(node) != cycleNodes.end()) return false;
        
        if(visited[node] == 1){
            cycleNodes.insert(node);
            return false;
        }
        visited[node] = 1;
        vector<int> neighbors = graph[node];
        
        for(auto& neighbor: neighbors){
            if(!dfs(neighbor, graph, visited)) {
                cycleNodes.insert(node);
                return false;
            }
        }
        visited[node] = 0;
        safeNodes.insert(node);
        return true;
    }
};