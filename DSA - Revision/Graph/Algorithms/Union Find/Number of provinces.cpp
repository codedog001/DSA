class Solution {
public:
    int n=0;
    vector<int> parent;
    vector<int> rank;
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        return unionFind(isConnected);
    }
    
private:
    int unionFind(vector<vector<int>>& isConnected){
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i; 
        
        int connectedComponents = n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(isConnected[i][j] == 1){
                    int parentI = findParent(i);
                    int parentJ = findParent(j);
                    
                    if(parentI != parentJ){
                        connectedComponents -= 1;
                        unionParents(parentI, parentJ);
                    }
                }
            }
        }
        
        return connectedComponents;
    }
    
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void unionParents(int u, int v){
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else if(rank[u] == rank[v]){
            parent[v] = u;
            rank[u] += 1;
        }
    }
};