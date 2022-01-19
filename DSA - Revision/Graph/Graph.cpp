#include <bits/stdc++.h>
using namespace std;

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
    bool flag = true;
    vector<int> color(n+1, -1);
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            if(!checkBipartiteBFS(i, color, visited, adj)){
                cout << "Not a bipartite graph." << endl;
                flag = false;
                break;
            }
        }
    }

    if(flag) cout << "It is a bipartite graph." << endl;
    

}                             
//Sample input with cycle:  
/*
8 8
6 4
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