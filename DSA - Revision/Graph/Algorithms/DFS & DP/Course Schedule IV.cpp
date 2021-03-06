// Logic: We have to check in query(u,v) whether path exisits from u -> v, if it exists, then u is prerequisite of v, else it not a prerequisite of v.

// Need of DP: Memoization saves time by storing paths that exist and that don't exist, else the logic is simple dfs for all queries and checking whether path exists.

class Solution {
public:
    vector<vector<int>> dp;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int nq = queries.size();
        vector<bool> result(nq, false);
        vector<vector<int>> adjList(numCourses);
        dp.resize(numCourses, vector<int>(numCourses, -1));
        
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
        }
        
        for(int i=0; i<nq; i++){
            int u = queries[i][0], v = queries[i][1];
            vector<int> visited(numCourses, 0);
            if(pathExistsDFS(u, v, adjList, visited)) result[i] = true;
        }
        return result;
    }
    
    bool pathExistsDFS(int u, int v, vector<vector<int>>& adjList, vector<int>& visited){
        if(u == v) return true;
        if(visited[u] == 1) return false;
        if(dp[u][v] != -1) return dp[u][v];
        
        visited[u] = 1;
        vector<int> neighbors = adjList[u];
        for(auto& neighbor: neighbors){
            if(pathExistsDFS(neighbor, v, adjList, visited)) {
                dp[u][v] = 1;
                return true;
            }
        }
        dp[u][v] = 0;
        return false;
    }
};