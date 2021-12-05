#include<bits/stdc++.h>
using namespace std;

void printGraphBFS(int n, int** edges, int startVertex, bool* visited){
    queue<int> q;
    q.push(startVertex);
    
    while(!q.empty()){
        int top = q.front();
        visited[top] = true;
        q.pop();
        cout << top << " ";
        for(int i=0; i<n; i++){
            if(edges[top][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


void printGraphDFS(int n, int** edges, int startVertex, bool* visited){
    cout << startVertex << endl;
    visited[startVertex] = true;
    for(int i=0; i<n; i++){
        if(visited[i] == true) continue;
        else if(edges[startVertex][i] == 1) printGraphDFS(n, edges, i, visited);
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];

    //Create an adjacency matrix with all false, showing no edges are connected currently
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    //Take input of edges and fill edges in adjacency matrix
    for(int i=0; i<e; i++){
        int f, s;
        //f and s are 2 vertices which have an edge b/w them.
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i])  printGraphDFS(n, edges, i, visited);
    }
    // 
    for(int i=0; i<n; i++){
        if(!visited[i])  printGraphBFS(n, edges, i, visited);
    }
    
}