#include<bits/stdc++.h>
using namespace std;

int findMinWeightVertex(vector<int>& weight, vector<bool>& visited, int n){
    int minWeightVertex = -1;
    for(int i=0; i<n; i++){
        //Agar minWeightVertex == -1 hai, mtlb we are finding source, and that will 
        // be vertex 0, since for loop is starting from 0.

        if(!visited[i] && (minWeightVertex == -1 || weight[i] < weight[minWeightVertex])) minWeightVertex = i;
    }
    return minWeightVertex;
}

void prims(vector<vector<int>>& edges, int n){
    vector<bool> visited(n, false);
    vector<int> weight(n, INT_MAX); //Us vertex tk reach krne ka minimum weight wala path.
    vector<int> parent(n,0);


    //According to algo
    weight[0] = 0;
    parent[0] = -1;
    
    //Step 1: Start from source and explore all neighbors
    for(int i=0; i<n-1; i++){
        //Find vertex to visit, that should be the vertex having minimum weight among 
        //all neighbours, pick it and mark it visited.
        int minWeightVertex = findMinWeightVertex(weight, visited, n);
        visited[minWeightVertex] = true;

        //Explore unvisited neighbors
        for(int j=0; j<n; j++){
            //Edge exists if weight in adj. matrix != 0
            if(edges[minWeightVertex][j] != 0 && !visited[j]){
                //If current weight of this vertex is lesser, then we will update its weight
                //and parent
                if(edges[minWeightVertex][j] < weight[j]) {
                    weight[j] = edges[minWeightVertex][j];
                    parent[j] = minWeightVertex;
                }
            }
        }
    }

    //Now print the result
    //Since 0 was the source, its parent is -1, therefore we will start printing from 
    //index 1 onwards
    for(int i=1; i<n; i++){
        //Print smaller vertex first 
        if(parent[i] < i) cout << parent[i] << " " << i << " " << weight[i] << endl;
        else cout << i << " " << parent[i] << " " << weight[i] << endl;
    }
}

int main() {
	int n, e;
    cin >> n >> e;
    
    vector<vector<int>> edges(n, vector<int>(n,0));
    for(int i=0; i<e; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[x][y] = z;
        edges[y][x] = z;
    }
    prims(edges, n);
    
}