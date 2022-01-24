// Logic: Since given graph is undirected, if nodes are in same component, there exists a path.

// Perform union on given edges, at the end, if nodes belong to same compenent they will have same parent, if they don't they're in different components.

// Or, perform DFS/BFS traversal, this is pretty straightforward, start from source, if destination is visited return true, else false.

// 1. Union By Rank and Find with Path Compression:
// T.C: O(n*α(n)) ≈ O(n)
// S.C: O(n)
// Read more about this time complexity here: https://leetcode.com/problems/redundant-connection/discuss/1295887/Easy-Solution-w-Explanation-or-All-Possible-Approaches-with-comments

class DSU{
    vector<int> parent, rank;
    public:
    DSU(int size){
        rank.resize(size, 0);
        parent.resize(size, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void unionByRank(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(rank[parU] < rank[parV]) parent[parU] = parV;
        else if(rank[parV] < rank[parU]) parent[parV] = parU;
        else if(rank[parU] == rank[parV]){
            parent[parU] = parV;
            rank[parV] += 1;
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int size = n+1;
        DSU ds(size);
        for(auto& edge:edges){
            int u = edge[0], v = edge[1];
            int parU = ds.findParent(u);
            int parV = ds.findParent(v);
            
            if(parU != parV) ds.unionByRank(u, v);
        }
        if(ds.findParent(source) == ds.findParent(destination)) return true;
        return false;
    }
};
2. DFS:
T.C: O(n+edges.size())
S.C: O(n+edges.size()) + O(n) + O(n) -> (Adj list, visited, stack space)

class Solution {
public:
    vector<int> visited;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n+1, 0);
        vector<int> undirAdjList[n+1];
        
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            undirAdjList[u].push_back(v);
            undirAdjList[v].push_back(u);
        }
        dfs(source, undirAdjList);
        return visited[destination] == 1;
    }
    
    void dfs(int node, vector<int> undirAdjList[]){
        visited[node] = 1;
        vector<int> neighbors = undirAdjList[node];
        for(auto& num: neighbors){
            if(visited[num] == 0) dfs(num, undirAdjList);
        }
    }
};