Logic: We have to count number of connected components and subtract 1 to find number of edges required to connect the graph.
// The code below is optimized version of union find: Union by rank and find with path compression.
// Time complexity: O(edges*α(n)) ≈ O(edges)

class DSU{
    vector<int> rank, parent;
    public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void unionParent(int u, int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        
        //In order to make graph connected, there should be at least n-1 edges
        if(edges < n-1) return -1;
        
        //Use union find to count number of connected components
        //No. of operations needed = TotalConnectedComp - 1.
        
        int connectedComponent = n;
        DSU ds(n);
        for(auto& edge: connections){
            int u = edge[0], v = edge[1];
            int parU = ds.findParent(u);
            int parV = ds.findParent(v);
            
            if(parU != parV){
                ds.unionParent(u, v);
                connectedComponent -= 1;
            }
        }
        return connectedComponent - 1;
    }
};