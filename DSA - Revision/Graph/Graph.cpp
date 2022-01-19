#include <bits/stdc++.h>
using namespace std;

void topologicalSortDFS(int i, vector<int>& visited, vector<int> adj[], stack<int>& st){
    if(visited[i] == 1) return;
    visited[i] = 1;
    vector<int> t = adj[i];
    for(auto &num: t){
        topologicalSortDFS(num, visited, adj, st);
    }
    st.push(i);
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

void doTopologicalSortDFS(int n, vector<int>& visited, vector<int> dirAdj[]){
    stack<int> st;
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            topologicalSortDFS(i, visited, dirAdj, st);
        }
    }

    //Print result of sorting
    cout << "Topological Sort Result: " << endl;
    while(!st.empty()){
        cout << st.top()<< " ";
        st.pop();
    }
}

void topologicalSortBFS(int n, vector<int> dirAdj[]){
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
        cout << node << " ";
        q.pop();
        vector<int> t = dirAdj[node];
        for(auto &num:t){
            indegree[num] -= 1;
            if(indegree[num] == 0) q.push(num);
        }
    }
}


int main(){
    int n, e;
    cin >> n >> e;

    //Create undirected adjacency list
    // vector<int> undirAdj[n+1];
    
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


    //Create directed adjacency list
    vector<int> dirAdj[n+1];
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        dirAdj[u].push_back(v);
    }

    //Detect cycle in directed graph using DFS
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
    
    

    //Topological sort: It is only possible for directed acyclic graph.
    // doTopologicalSortDFS(n, visited, dirAdj);

    //BFS topological sort is also known as kahn's algo.
    topologicalSortBFS(n, dirAdj); 

}                             
//Sample input with cycle:  
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
7 9
*/