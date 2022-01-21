#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int u;
    int v;
    int w;

    Node(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(){
    vector<Node> edges;
    int n, e;
    cin >> n >> e;

    //T.C - O(e*(n-1)) => O(n^3) in worst case => Worst Case: connected graph where e = (n(n-1))/2.

    //1. Take input in edges vector.
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Node(u,v,w));
    }

    // 2. Create vector distance
    // Why custom infinity? Because in 5th step we will be adding this distance to edge wt, 
    // it might go out of bounds if taken INT_MAX

    int infinity = 1000000;
    vector<int> distance(n+1, infinity);

    //3. Get input of source
    int source = 0;
    cout << "Enter source node: " << endl;
    cin >> source;

    //4. Set distance to source = 0
    distance[source] = 0;

    //5. Relax all edges for (n-1) times.
    for(int i=1; i<=n-1; i++){
        for(auto& edge: edges){
            int distanceU = distance[edge.u], edgeWt = edge.w, distanceV = distance[edge.v];
            int newDistance = distanceU + edgeWt;

            if(newDistance < distanceV){
                distance[edge.v] = newDistance; 
            }
        }
    }

    //6. Detect if graph contains negative weight cycle, a cycle whose overall weight < 0 will
    //give wrong result in bellman ford.

    //If after (n-1) cycles, the distance of any node gets changed on relaxing one more time
    //that implies a negative weight cycle exists and results won't be correct by this algo.

    //So relax all edges just one more time.
    bool negativeCycleExists = false;

    for(auto &edge:edges){
        int distanceU = distance[edge.u], edgeWt = edge.w, distanceV = distance[edge.v];
        int newDistance = distanceU + edgeWt;

        if(newDistance < distanceV){
            negativeCycleExists = true;
            distance[edge.v] = newDistance; 
            break;
        }
    }

    if(negativeCycleExists) cout << "Negative weight cycle detected in directed graph!" << endl;
    else{
        cout << "Minium weight path from " << source << " to all nodes" << endl;
        for(int i=1; i<=n; i++){
            cout << source << " - " << i << " weight: " << distance[i] << endl;
        }
    }

}