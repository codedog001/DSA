#include <bits/stdc++.h>
using namespace std;


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

int main(){
    int n, e;
    cin >> n >> e;

    //Create adjacency list
    vector<int> adj[n+1];
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Print adjacency list
    // for(int i=1; i<=n; i++){
    //     vector<int> p = adj[i];
    //     cout << "Node: " << i << " ";
    //     for(auto &num:p) cout<< num << " ";
    //     cout << endl;
    // }

    vector<int> visited(n+1, 0);

    cout << "BFS Traversal" << endl;
    // Traversal
    for(int i=1; i<=n; i++){
        if(visited[i] == 0) {
            dfs(i, visited, adj);
        }
    }
    cout << "DFS Traversal" << endl;
    for(int i=1; i<=n; i++){
        if(visited[i] == 0) {
            dfs(i, visited, adj);
        }
    }

}