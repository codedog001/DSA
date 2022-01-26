A dry run of solution below on pen & paper would make the solution easier to understand.
This is not kosaraju's opposite, if a node not involved in strongly connected component leads to a strongly connected component then also it is not a safe node, but according to kosaraju that node will be an individual strongly connected component, hence it is not opposite of kosaraju.
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