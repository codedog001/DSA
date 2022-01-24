//1. Union by rank and Find with path compression:
//T.C: O(n*α(n)) ≈ O(n)
//Refer this for indepth explanation: https://leetcode.com/problems/redundant-connection/discuss/1295887/Easy-Solution-w-Explanation-or-All-Possible-Approaches-with-comments

class DSU {
    vector<int> parent, rank;
    public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]); //Path compression
    }
    
    void unionByRank(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(rank[parU] < rank[parV]){
            parent[parU] = parV;
        }
        else if(rank[parV] < rank[parU]){
            parent[parV] = parU;
        }
        else if(rank[parU] == rank[parV]){
            parent[parU] = parV;
            rank[parV] += 1;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        //Since nodes are starting from 1, vectors will be of size n+1.
        int size = n+1;
        DSU ds(n+1);
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            int parU = ds.findParent(u);
            int parV = ds.findParent(v);
            
            if(parU != parV) ds.unionByRank(u, v);
            else return {u, v};
        }
        return {-1,-1};
    }
};

// 2. DFS: Store all edges that cause cycle into a set, and go through the given edges from the end, return the one that matches.

class Solution {
public:
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
        detectCycleDFS(source, parent, undirAdjList);
        
        for(int i=n-1; i>=0; i--){
            vector<int> v = edges[i];
            if(st.find(v[0]) != st.end() && st.find(v[1]) != st.end()) return v;
        }
        return {-1,-1};
    }
    
    private:
    int cycleStartNode = -1;
    bool isCycle = false;
    unordered_set<int> st;
    
    void detectCycleDFS(int node, int parent, vector<int> undirAdjList[]){
        if(visited[node] == 1){
            isCycle = true;
            cycleStartNode = node;
            st.insert(node);
            return;
        }
        visited[node] = 1;
        vector<int> neighbors = undirAdjList[node];
        
        for(auto& neighbor: neighbors){
            if(neighbor == parent) continue;
            
            //DFS will be performed until cycle is not detected, once set starts getting filled no further nodes will be visited
            if(st.empty()) detectCycleDFS(neighbor, node, undirAdjList);
            if(isCycle) st.insert(node);
            if(cycleStartNode == node) isCycle = false;
        }
    }
};