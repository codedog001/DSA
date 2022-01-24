Note: I have not defined very large value as INT_MAX, because we need to add that value at some point to current edge weight and that will cross integer range giving wrong values, so refrain from using INT_MAX, instead define some other high value or take long long or something.

#define pii pair<int, int>
#define Inf 1000000

class Solution {
public:
    vector<int> distance, visited;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int size = n+1;
        vector<pii> adjList[n+1];
        distance.resize(n+1, Inf);
        visited.resize(n+1, 0);
        
        for(auto& edge: times){
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v,w});
        }
        dijkstra(adjList, n, k);
        for(int i=1; i<=n; i++){
            if(visited[i] == 0) return -1;
        }
        
        auto maxi = *max_element(distance.begin(), distance.end());
        return maxi;
    }
    
    void dijkstra(vector<pii> adjList[], int n, int source){
        distance[source] = 0;
        distance[0] = -1; //0 is not a valid node in this problem, so assign it something unreasonable.
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0, source});
        visited[source] = 1;
        
        while(!minHeap.empty()){
            pii p = minHeap.top();
            minHeap.pop();
            int node = p.second, nodeWt = p.first;
            vector<pii> neighbors = adjList[node];
            
            for(auto& neighborPair: neighbors){
                //Check whether cost of reaching neighbor is lower when visited through this node
                int neighbor = neighborPair.first, edgeWt = neighborPair.second;
                int oldNeighborWt = distance[neighbor], newNeighborWt = nodeWt + edgeWt;
                
                if(newNeighborWt < oldNeighborWt){
                    visited[neighbor] = 1;
                    distance[neighbor] = newNeighborWt;
                    minHeap.push({newNeighborWt, neighbor});
                }
            }
        }
    }
};