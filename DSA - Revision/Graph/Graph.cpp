#include <bits/stdc++.h>
using namespace std;

void topologicalSortDFS(int i, vector<int>& visited, vector<int> adj[], stack<int>& st, stack<int>& stForSomeOtherFun){
    if(visited[i] == 1) return;
    visited[i] = 1;
    vector<int> t = adj[i];
    for(auto &num: t){
        topologicalSortDFS(num, visited, adj, st, stForSomeOtherFun);
    }
    st.push(i);
    stForSomeOtherFun.push(i);
}

bool directedGraphHasCycleDFS(int i, vector<int>& visited, vector<int>& currentCallVisited, vector<int> adj[]){
    if(visited[i] == 1 && currentCallVisited[i] == 1) return true;
    else if(visited[i] == 1) return false;

    visited[i] = 1;
    currentCallVisited[i] = 1;

    vector<int> t = adj[i];
    for(auto &num:t){
        if(directedGraphHasCycleDFS(num, visited, currentCallVisited, adj)) return true;
    }
    currentCallVisited[i] = 0;

    return false;
}



bool checkBipartiteDFS(int i, vector<int>& color, vector<int>& visited, vector<int> adj[]){
    visited[i] = 1;
    if(color[i] == -1) color[i] = 1;
    vector<int> t = adj[i];
    for(auto& num:t){
        if(visited[num] == 0){
            color[num] = 1-color[i];
            if(!checkBipartiteDFS(num, color, visited, adj)) return false;
        }
        else if(visited[num] == 1 && color[num] == color[i]) return false;
    }

    return true;
}


bool checkBipartiteBFS(int i, vector<int>& color, vector<int>& visited, vector<int> adj[]){
    queue<int> q;
    q.push(i);
    color[i] = 0;

    while(!q.empty()){
        int node = q.front();
        vector<int> t = adj[node];
        q.pop();
        for(auto& num: t){
            int desiredColor = color[node]^1;
            if(visited[num] == 0){
                visited[num] = 1;
                color[num] = desiredColor;
                q.push(num);
            }
            else if(visited[num] == 1 && color[num] != desiredColor) return false;
        }
    }

    return true;
}

bool hasCycleBFS(int i, vector<int>& visited, vector<int> adj[]){
    queue<pair<int,int>> q;

    q.push({i,-1});
    visited[i] = 1;
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        vector<int> t = adj[node];
        for(auto& num: t){
            if(visited[num] == 0){
                visited[num] = 1;
                q.push({num, node});
            }
            else if(visited[num] == 1 &&  parent != num) return true;
        }
    }
    return false;
}


bool hasCycleDFS(int i, int parent, vector<int>& visited, vector<int> adj[]){
    visited[i] = 1;

    vector<int> t = adj[i];
    for(auto &num: t){
        if(visited[num] == 0){
            if(hasCycleDFS(num, i, visited, adj)) return true;
        }
        else if(visited[num] == 1 && parent != num) return true;
    }
    return false;
}

void dfs(int i, vector<int>& visited, vector<int> adj[]){
    if(visited[i] == 1) return;
    visited[i] = 1;

    cout << i << " ";
    vector<int> t = adj[i];
    for(auto& num:t){
        dfs(num, visited, adj);
    }
}

void doDFS(vector<int> adj[], int n){
    vector<int> visited(n+1, 0);
    for(int i=1; i<=n; i++){
        if(visited[i] == 0) {
            dfs(i, visited, adj);
        }
    }
}

void bfs(int i, vector<int>& visited, vector<int> adj[]){
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        vector<int> t = adj[node];
        for(auto &num:t){
            if(visited[num] == 0){
                visited[num] = 1;
                q.push(num);
            }
        }
    }
}

void doTopologicalSortDFS(int n, vector<int>& visited, vector<int> dirAdj[], stack<int>& stForSomeFunction){
    stack<int> st;
    for(int i=0; i<=n; i++){
        if(visited[i] == 0){
            topologicalSortDFS(i, visited, dirAdj, st, stForSomeFunction);
        }
    }

    //Print result of sorting
    // cout << "Topological Sort Result: " << endl;
    // while(!st.empty()){
    //     cout << st.top()<< " ";
    //     st.pop();
    // }
}

void topologicalSortBFS(int n, vector<int> dirAdj[], vector<int>& res){
    vector<int> indegree(n+1, 0);

    //1. Store indegree of each node in a vector
    for(int i=1; i<=n; i++){
        vector<int> to = dirAdj[i];
        for(auto &num:to){
             indegree[num]++;
        }
    }

    queue<int> q;
    //2. First push those nodes into queue whose indegree == 0.
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        res.push_back(node);
        q.pop();
        vector<int> t = dirAdj[node];
        for(auto &num:t){
            indegree[num] -= 1;
            if(indegree[num] == 0) q.push(num);
        }
    }
}

void directedHasCycleBFS(int n, vector<int> dirAdj[]){
    vector<int> res;
    topologicalSortBFS(n, dirAdj, res);
    if(res.size() < n) {
        cout << "Directed Graph has cycle, checked through BFS" << endl;
    }
    else cout << "Directed Graph doesn't have cycle, checked through BFS" << endl;;
}

void doTopologicalSortBFS(int n, vector<int> dirAdj[]){
    vector<int> res;
    topologicalSortBFS(n, dirAdj, res);
    //Print result of sorting
    cout << "Topological Sort Result: " << endl;
    for(auto& n:res){
        cout << n << " ";
    }    
    cout << endl;
}

void shortestDistance(int source, vector<int>& distance, vector<int> undirAdj[], int n){
    queue<int> q;
    q.push(source);
    distance[source] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vector<int> t = undirAdj[node];
        for(auto &num:t){
            int curDistance = distance[node] + 1;
            if(curDistance < distance[num]){
                distance[num] = curDistance;
                q.push(num);
            }
        }
    }
}

void getShortestPath(vector<int> undirAdj[], int n){
    vector<int> distance(n+1, INT_MAX);
    int source = 1;
    shortestDistance(source, distance, undirAdj, n);
    for(int i=0; i<=n; i++){
        cout << "Distance of " << i << " from source is: "<< distance[i] << endl;
    }
}

void inputDirectedAcyclicWeightedGraph(vector<pair<int, int>> adj[], int e){
    cout << "Enter u, v, w of directed acyclic weighted graph" << endl;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}

void findShortestPathInDAWG(int source, vector<pair<int, int>> dirWtdAdj[], int n, vector<int>& visited){
    //Step 1: Get result of topological sort
    stack<int> st;

    //Another temporary adj list is created just to get result from topo sort without creating
    //new function for this adj list because it has weights.
    vector<int> tempAdjForTopoSort [n+1];
    for(int i=0; i<n+1; i++){
        vector<pair<int, int>> t = dirWtdAdj[i];
        for(pair<int, int>n: t){
            tempAdjForTopoSort[i].push_back(n.first);
        }
    }
    doTopologicalSortDFS(n, visited, tempAdjForTopoSort, st);

    //Now stack has result of topo sort.

    //Step 2: distance array
    vector<int> distance(n+1, INT_MAX);

    //Step 3. Distance of source is 0.
    distance[source] = 0;

    //Step 4: Pop out nodes one by one from stack and calculate distance of thier neighbors
    while(!st.empty()){
        int node = st.top();
        st.pop();
        vector<pair<int, int>> t = dirWtdAdj[node];
        for(auto& p:t){
            int curDistance = distance[node] + p.second;
            int neighbor = p.first;
            if(curDistance < distance[neighbor]) distance[neighbor] = curDistance;
        }
    }

    //Step 5: Print out the shortest distance from source to all nodes
    cout << endl << endl;
    cout << "Shortest Distance from " << source << " to all nodes in Directed Acyclic Weighted Graph: " << endl;
    for(int i = 0; i<=n; i++){
        cout << source << " to " << i << " : " << distance[i] << endl;
    }
}


void findShortestPathInUWG(int n, int source, vector<pair<int, int>> adj[]){
    //Create minHeap to store {distance, node} pair.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    //Create distance array.
    vector<int> distance(n+1, INT_MAX);

    //Assign distance[source] = 0.
    distance[source] = 0;

    //Push source node to minHeap
    minHeap.push({0, source});

    //Find minimum distance to all nodes from source node.
    while(!minHeap.empty()){
        pair<int, int> p = minHeap.top();
        minHeap.pop();
        int node = p.second;
        int distToThisNode = p.first;

        vector<pair<int, int>> t = adj[node];
        for(pair<int, int> c: t){
            int neighbor = c.first;
            int pathWeight = c.second;

            int distanceFromNode = distToThisNode + pathWeight;
            int previousDistance = distance[neighbor];

            if(distanceFromNode < previousDistance){
                distance[neighbor] = distanceFromNode;
                minHeap.push({distanceFromNode, neighbor});
            }
        }
    }

    //Print the result
    cout << endl << endl;
    cout << "Shortest Distance from " << source << " to all nodes in Undirected Weighted Graph using Dijkstra: " << endl;
    for(int i = 0; i<=n; i++){
        cout << source << " to " << i << " : " << distance[i] << endl;
    }

}

void inputUndirectedWeightedGraph(vector<pair<int, int>> adj[], int e){
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
}

void findMSTUsingPrims(vector<pair<int, int>> udirWtdAdj[], int e, int n){
    //1. Create visited, weight and parent array, and a priority queue to quickly pick up next node
    //having miniumum weight.
    //Storage in priority queue: {weight, node}
    //Storage in adj list: {node, weight}

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> visited(n+1, 0);
    vector<int> weight(n+1, INT_MAX);
    vector<int> parent(n+1, -1);

    //2. Assume source as 0 initially.
    weight[0] = 0;
    parent[0] = -1; 
    minHeap.push({0,0});

    while(!minHeap.empty()){
        //3. Visit neighbors (BFS) of current node and assign them current edge weight if(curEdgeWt < weight[neighbor])
        pair<int, int> p = minHeap.top();
        minHeap.pop();
        int node = p.second;
        int nodeWeight = p.first;

        vector<pair<int, int>> t = udirWtdAdj[node];
        for(pair<int, int> d: t){
            int neighbor = d.first;
            int newEdgeWeight = d.second;
            int oldWeight = weight[neighbor];

            //4. Remember: Visit only unvisited neighbors
            if(visited[neighbor] == 0 && newEdgeWeight < oldWeight){
                //5. Update parent, weight and push this node into minHeap.
                parent[neighbor] = node;
                weight[neighbor] = newEdgeWeight;
                minHeap.push({newEdgeWeight, neighbor});
            }
        }

        //5. Mark current node as visited
        visited[node] = 1;
    }

    //Now, parent contains, parent of all nodes in MST, and weight contains the minimum edge weight required to connect to the node.
    //Therefore, print the result
    int totalWeight = 0;
    for(int i=0; i<=n; i++){
        cout << "Parent of node " <<  i << " is " << parent[i] << ". Edge weight: " << weight[i] << endl; 
        totalWeight += weight[i];
    }

    cout << endl << "Total Weight is: " << totalWeight <<endl;
}

void inputUndirAdj(int e, vector<int> undirAdj[]){
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u>> v;
        undirAdj[u].push_back(v);
        undirAdj[v].push_back(u);
    }
}

void dfsToFindBridges(int curNode, int parent, vector<int>& visited, vector<int> undirAdj[], int timer, vector<int>& lowTime, vector<int>& inTime, vector<pair<int, int>>& result){
    visited[curNode] = 1;
    inTime[curNode] = lowTime[curNode] = timer;

    vector<int> t = undirAdj[curNode];
    for(auto& num:t){
        if(num == parent) continue;
        else if(visited[num] == 1){
            //Back edge
            lowTime[curNode] = min(lowTime[curNode], inTime[num]);
        }
        else if(visited[num] == 0){
            //Forward Edge
            //1. Call DFS
            timer+= 1;
            dfsToFindBridges(num, curNode, visited, undirAdj, timer, lowTime, inTime, result);

            //2. Check if this edge with the neighbor is a bridge
            if(inTime[curNode] < lowTime[num]){
                result.push_back({curNode, num});
            }

            //3. CurNode will update its lowTime if it could be reduced
            lowTime[curNode] = min(lowTime[curNode], lowTime[num]);
        }
    }
}

void findBridges(int n, vector<int> undirAdj[]){
    vector<int> visited(n+1, 0);
    static int timer = 1;
    vector<int> lowTime(n+1, 0);
    vector<int> inTime(n+1, 0);
    vector<pair<int, int>> result;
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            dfsToFindBridges(i, -1, visited, undirAdj, timer, lowTime, inTime, result);
        }
    }

    //Print Result
    for(auto& p:result){
        cout << "Edge: " << p.first << " - " << p.second << " is a bridge" << endl;
    }
}

void dfsToFindArticulationPoints(int curNode, int parent, vector<int>& visited, vector<int> undirAdj[], int timer, vector<int>& lowTime, vector<int>& inTime, unordered_set<int>& result){
    visited[curNode] = 1;
    inTime[curNode] = lowTime[curNode] = timer;

    vector<int> t = undirAdj[curNode];
    for(auto& num:t){
        if(num == parent) continue;
        else if(visited[num] == 1){
            //Back edge
            lowTime[curNode] = min(lowTime[curNode], inTime[num]);
        }
        else if(visited[num] == 0){
            //Forward Edge
            //1. Call DFS
            timer+= 1;
            dfsToFindArticulationPoints(num, curNode, visited, undirAdj, timer, lowTime, inTime, result);

            //2. CurNode will update its lowTime if it could be reduced, if it could 
            //be reduced that means child could reach an ancestor and therefore curNode could
            //also reach that ancestor
            lowTime[curNode] = min(lowTime[curNode], lowTime[num]);

            
            //3. Check if this edge with the neighbor is a bridge
            if(lowTime[num] >= inTime[curNode] && parent != -1){
                result.insert(curNode);
            }
        }

        //Check if root is an articulation point
        if(parent == -1 && t.size() > 1) result.insert(curNode);
    }
}

void findArticulationPoints(int n, vector<int> undirAdj[]){
    vector<int> visited(n+1, 0);
    static int timer = 1;
    vector<int> lowTime(n+1, 0);
    vector<int> inTime(n+1, 0);
    unordered_set<int> result;
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            dfsToFindArticulationPoints(i, -1, visited, undirAdj, timer, lowTime, inTime, result);
        }
    }

    //Print Result
    for(auto& p:result){
        cout << "Node: " << p << " is an articulation point." << endl;
    }
}

void inputDirAdjList(vector<int> dirAdj[], int e){
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        dirAdj[u].push_back(v);
    }
}

void findStronglyConnectedComponentUsingKosaraju(int n, vector<int> dirAdj[]){
    stack<int> st;
    vector<int> visited(n+1, 0);

    //1. Find result of topo sort
    doTopologicalSortDFS(n, visited, dirAdj, st);

    //2. Transpose given graph
    //E.g: 1->2->3<-4 => 1<-2<-3->4
    vector<int> transposeAdj[n+1];

    for(int i=1; i<=n; i++){
        vector<int> t = dirAdj[i];

        //We will do dfs again, so assign 0 in visited.
        visited[i] = 0;
        for(auto& num:t){
            transposeAdj[num].push_back(i);
        }
    }

    cout << "Strongly Connected Components are: " << endl;
    //3. Pop out nodes 1 by 1 from result of topo sort and apply dfs on them on transposed graph.
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(visited[node] == 0) {
            dfs(node, visited, transposeAdj);
            cout << endl;
        }
    }
    cout << endl;
}   

int main(){
    int n, e;
    cin >> n >> e;

    //Create undirected adjacency list
    // vector<int> undirAdj[n+1];
    // inputUndirAdj(e, undirAdj);
    

    

    // Print adjacency list
    // for(int i=1; i<=n; i++){
    //     vector<int> p = adj[i];
    //     cout << "Node " << i << " has edge with ";
    //     for(auto &num:p) cout<< num << " ";
    //     cout << endl;
    // }

    vector<int> visited(n+1, 0);

//--------------------------------------------------------------------------------------------------

    // cout << "BFS Traversal" << endl;
    // Traversal
    // for(int i=1; i<=n; i++){
    //     if(visited[i] == 0) {
    //         dfs(i, visited, adj);
    //     }
    // }
    // cout << "DFS Traversal" << endl;
    // doDFS(adj, n);


//--------------------------------------------------------------------------------------------------

    //Check Cycle through DFS
    // bool flag = false;
    // for(int i=1; i<=n; i++){
    //     if(visited[i] == 0){
    //         if(hasCycleDFS(i, -1, visited, adj)){
    //             cout << "Cycle Exists" << endl;
    //             flag = true;
    //             break;
    //         }
    //     }
    // }
    // if(!flag) cout << "Cycle Doesn't exist" << endl;

    //Check cycle through BFS
    // bool flag = false;
    // for(int i=1; i<=n; i++){
    //     if(visited[i] == 0){
    //         if(hasCycleBFS(i, visited, adj)){
    //             cout << "Cycle Exists" << endl;
    //             flag = true;
    //             break;
    //         }
    //     }
    // }
    // if(!flag) cout << "Cycle Doesn't exist" << endl;

//--------------------------------------------------------------------------------------------------
    //Check if graph is bipartite through BFS
    // bool flag = true;
    // vector<int> color(n+1, -1);
    // for(int i=1; i<=n; i++){
    //     if(visited[i] == 0){
    //         if(!checkBipartiteBFS(i, color, visited, adj)){
    //             cout << "Not a bipartite graph." << endl;
    //             flag = false;
    //             break;
    //         }
    //     }
    // }

    // if(flag) cout << "It is a bipartite graph." << endl;

    //Check if graph is bipartite through DFS
    // bool flag = true;
    // vector<int> color(n+1, -1);
    // for(int i=1; i<=n; i++){
    //     if(visited[i] == 0){
    //         if(!checkBipartiteDFS(i, color, visited, undirAdj)){
    //             cout << "Not a bipartite graph." << endl;
    //             flag = false;
    //             break;
    //         }
    //     }
    // }

    // if(flag) cout << "It is a bipartite graph." << endl;


//  --------------------------------------------------------------------------------------------

    //Detect cycle in directed graph
    //0. Using BFS (Kahn's algo): It is done by topological sort, if o.p of topological sort < n -> graph contains cycle.
    // directedHasCycleBFS(n, dirAdj);

    //1. using DFS
    //It uses one more visited array other than normal visited array to keep track of nodes traversed in current DFS call.
    // vector<int> currentCallVisited(n+1, 0);
    
    //Create directed adjacency list
    // vector<int> dirAdj[n+1];
    // inputDirAdjList(dirAdj, e);


    // bool flag = false;
    // for(int i=1; i<=n; i++){
    //     if(directedGraphHasCycleDFS(i, visited, currentCallVisited, dirAdj)){
    //         cout << "Given directed graph contains cycle." << endl;
    //         flag = true;
    //         break;
    //     }
    // }
    // if(!flag) cout<< "Given directed graph does not contain cycle." << endl;
    
//---------------------------------------------------------------------------------------------

    //Topological sort: It is only possible for directed acyclic graph.
    // doTopologicalSortDFS(n, visited, dirAdj);

    //kahn's algo: BFS topological sort.
    // doTopologicalSortBFS(n, dirAdj); 

//------------------------------------------------------------------------------------------------

    //Shortest path from source to all other nodes in undirected graph with unit weight
    //It is calculated through BFS
    // getShortestPath(undirAdj, n);

//------------------------------------------------------------------------------------------------

    //Shortest path from source node to all other nodes in Directed Acyclic Weighted graph (DAG)
    //Steps:
    //1. Get output of topological sort
    //2. Create distance array with values INT_MAX
    //3. Assign distance[source] = 0
    //4. Take nodes out one by one from result stack of topological sort, and visit neighbors of these
    //nodes, and assing minimum(current cost, old cost).
    //5. By the end, array will have minimum cost from source to all nodes.

    // vector<pair<int, int>> dirAcyclicWtdAdj[n+1];
    // inputDirectedAcyclicWeightedGraph(dirAcyclicWtdAdj, e);

    // cout << "OUTPUT: " << endl;
    // for(int i=0; i<=n; i++){
    //     vector<pair<int, int>> t = dirAcyclicWtdAdj[i];
    //     cout <<"Node " << i << "has edge with: " << endl;
    //     for(int j=0; j< t.size(); j++){
    //         cout << t[j].first << " having weight: " << t[j].second << endl;;
    //     }
    // }

    // int source = 0;
    // findShortestPathInDAWG(source, dirAcyclicWtdAdj, n, visited);

// ----------------------------------------------------------------------------------------------------------------
    
    //Dijkstra's Algorithm: Shortest path from source to destination in undirected weighted graph.
    //1. Create adj list.
    //2. Create minHeap to store {distance, node} pair.
    //3. Create distance array.
    //4. Assign distance[source] = 0.
    //5. Push {0,source} node to minHeap.
    //6. Find minimum distance to all nodes from source node.
    //7. Print result.
     
    // vector<pair<int, int>> undirWtdAdj[n+1];
    // inputUndirectedWeightedGraph(undirWtdAdj, e);

    // int source = 1;
    // findShortestPathInUWG(n, source, undirWtdAdj);

// ----------------------------------------------------------------------------------------------------------------

    //Prims Algorithm to find MST of given undirected connected graph
    //1. Create adj list.
    //2. Other steps described in function
    // vector<pair<int, int>> undirWtdAdj[n+1];
    // inputUndirectedWeightedGraph(undirWtdAdj, e);

    // findMSTUsingPrims(undirWtdAdj, e, n);

// ----------------------------------------------------------------------------------------------------------------
    //Kruskals algorithm in kruskal.cpp

// ----------------------------------------------------------------------------------------------------------------

    //Find Bridges in graph
    // vector<int> undirAdj[n+1];
    // inputUndirAdj(e, undirAdj);

    // findBridges(n, undirAdj);

// ----------------------------------------------------------------------------------------------------------------

    //Find Articulation Points in graph
    // vector<int> undirAdj[n+1];
    // inputUndirAdj(e, undirAdj);

    // findArticulationPoints(n, undirAdj);

// -----------------------------------------------------------------------------------------------------------------

    //Kosaraju's Algo: Find strongly conneected components in directed graph
    //Steps:
    //1. Find topo sort - Can't be called topo sort because topo sort works for Directed acyclic graph
    //But, the result needed is same as result of topo sort, so called topo sort.
    //2. Transpose the given graph.
    //3. Pop out each node from stack one by one and DFS on it on transposed graph.

    vector<int> dirAdj[n+1];
    inputDirAdjList(dirAdj, e);

    findStronglyConnectedComponentUsingKosaraju(n, dirAdj);


}                             
//Undirected graph with cycle:  
/*
8 8
8 4
5 7
3 2
7 4
6 8
1 5
5 6
5 3
*/

//Sample input without cycle
/*
8 7
5 7
3 2
7 4
6 8
1 5
5 6
5 3
*/

//Direct graph with cycle
/*
9 10
1 2
2 3
3 4
4 5
3 6
6 5
7 2
7 8
8 9
9 7
*/

//Directed Acyclic graph with weight
/*
6 7
0 1 2
1 2 3
2 3 6
0 4 1
4 2 2 
4 5 4
5 3 1
*/

//Undirected Weighted Graph
/*
5 6
1 2 2
2 3 4
3 4 3
1 4 1
2 5 5
3 5 1
*/

//Undirected Weighted Graph (used in Prims)
/*
4 6
0 1 2
1 2 3
0 3 6
1 4 5
1 3 8 
2 4 7
*/