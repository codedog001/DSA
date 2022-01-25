1. Dijkstra Variation:
Note: This problem can't be solved through Dijkstra without modification. Dijkstra will only revisit path with miniumum weight, but that's not sufficient, we also need to revisit node having higher weight but lesser stops.

For E.g:
5
[[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]
0
2
2

Dijkstra will assign node 1 weight 4: 0 -> 3 -> 1. Then it will travel node to node 2: 0 -> 3 -> 1 -> 2 giving weight 9.
As soon as we change weight of 1 from 5 to 4 and add a stop through normal Dijkstra, we can't reach correct solution,
which is to reach node 2 through 0 -> 1 -> 4 -> 2 with weight 7.
Sum Up: Hence we need to modify Dijkstra, to consider 2nd path 0->1 even if node 1 has weight 5, but has only 1 stop unlike 1st path where node 1 takes 2 stops.

Below is the code applying same thing, a dry run on above example will improve understanding of this method.
T.C - O(v + elogv)

I have attached the link to tutorial at the end of solution, it helped me understand the solution, so if my explanation doesn't help, you can watch that tutorial.

#define tii tuple<int, int, int>
#define pii pair<int, int>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pii> adjList[n];
        for(auto& flight: flights){
            int source = flight[0], dest = flight[1], price = flight[2];
            adjList[source].push_back({dest, price});
        }
        return dijkstraVariation(adjList, n, src, dst, k);
    }
    
    int dijkstraVariation(vector<pii> adjList[], int n, int node, int dst, int k){
        priority_queue<tii, vector<tii>, greater<tii>> minHeap;
        vector<int> stops(n, INT_MAX), distance(n, INT_MAX);
        
        stops[node] = 0;
        distance[node] = 0;
        minHeap.push({0,node,0});
        
        while(!minHeap.empty()){
            auto [curDist, curNode, curStops] = minHeap.top();
            minHeap.pop();
            if(curNode == dst) return curDist;
            if(curStops == k+1) continue;
            
            auto neighbors = adjList[curNode];
            for(auto& neighborPair :neighbors){
                int neighbor = neighborPair.first, edgeWt = neighborPair.second;
                int nextDistance = curDist + edgeWt, nextStops = curStops+1;
                
				//This if check is same as normal Dijkstra
                if(distance[neighbor] > nextDistance){
                    distance[neighbor] = nextDistance;
                    stops[neighbor] = nextStops;
                    minHeap.push({nextDistance, neighbor, nextStops});
                }
                
                //This is main variation from Dijkstra
                else if(nextStops < stops[neighbor]){
                    stops[neighbor] = nextStops;
                    minHeap.push({nextDistance, neighbor, nextStops});
                }
            }
        }
        return -1;
    }
};
2. Bellman Ford Variation:
This problem can be solved using Bellman Ford algorithm by performing k+1 relaxations, that's it, if after k+1 relaxations price is not INT_MAX, then return price otherwise return -1.

Link to tutorial is attached at the end of solution.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return bellmanFordVariation(flights, n, src, dst, k);
    }
    
    int bellmanFordVariation(vector<vector<int>>& flights, int n, int src, int dst, int k){
        vector<int> price(n, 10000000), tempPrice(n, 10000000);
        price[src] = tempPrice[src] = 0;
        
        //Relax k+1 times
        for(int i=1; i<=k+1; i++){
            for(auto& edge: flights){
                int source = edge[0], destination = edge[1], edgeCost = edge[2];
                int newCost = price[source] + edgeCost;
                
                if(newCost < tempPrice[destination]) tempPrice[destination] = newCost;
            }

			//Copy tempPrice to price
            for(int i=0; i<n; i++) price[i] = tempPrice[i];
        }
        return price[dst] == 10000000 ? -1 : price[dst];
    }
};