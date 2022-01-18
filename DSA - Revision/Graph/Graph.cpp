#include <bits/stdc++.h>
using namespace std;


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

    // Print adjacency list
    for(int i=1; i<=n; i++){
        vector<int> p = adj[i];
        cout << "Node " << i << " has edge with ";
        for(auto &num:p) cout<< num << " ";
        cout << endl;
    }

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
    bool flag = false;
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            if(hasCycleDFS(i, -1, visited, adj)){
                cout << "Cycle Exists" << endl;
                flag = true;
                break;
            }
        }
    }
    if(!flag) cout << "Cycle Doesn't exist" << endl;
    

}                             
//Sample input with cycle:  
/*
9 7
8 4
5 7
3 2
7 4
6 8
1 5
5 6
*/

//Sample output without cycle
/*
8 7
5 7
3 2
7 4
6 8
1 5
5 6
*/