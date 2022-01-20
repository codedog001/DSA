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
    cout << "Topological Sort Result: " << endl;
    while(!st.empty()){
        cout << st.top()<< " ";
        st.pop();
    }
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


int main(){
    int n, e;
    cin >> n >> e;

    //Create undirected adjacency list
    vector<int> undirAdj[n+1];
    
    // for(int i=0; i<e; i++){
    //     int u, v;
    //     cin >> u>> v;
    //     undirAdj[u].push_back(v);
    //     undirAdj[v].push_back(u);
    // }

    

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
    // for(int i=1; i<=n; i++){
    //     if(visited[i] == 0) {
    //         dfs(i, visited, adj);
    //     }
    // }

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

//--------------------------------------------------------------------------------------------------

    //Create directed adjacency list
    // vector<int> dirAdj[n+1];
    // for(int i=0; i<e; i++){
    //     int u, v;
    //     cin >> u >> v;
    //     dirAdj[u].push_back(v);
    // }

// ----------------------------------------------------------------------------------------------

    //Detect cycle in directed graph
    //0. Using BFS (Kahn's algo): It is done by topological sort, if o.p of topological sort < n -> graph contains cycle.
    // directedHasCycleBFS(n, dirAdj);

    //1. using DFS
    //It uses one more visited array other than normal visited array to keep track of nodes traversed in current DFS call.
    // vector<int> currentCallVisited(n+1, 0);
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

    //BFS topological sort is also known as kahn's algo.
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
    
    //Dijkstra's Algorithm
    //Shortest path from source to destination in undirected weighted graph
    //1. Create adj list
     
    vector<pair<int, int>> undirWtdAdj[n+1];
    inputUndirectedWeightedGraph(undirWtdAdj, e);

    int source = 1;
    findShortestPathInUWG(n, source, undirWtdAdj);

// ----------------------------------------------------------------------------------------------------------------



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