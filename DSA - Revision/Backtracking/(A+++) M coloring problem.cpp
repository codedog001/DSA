vector<int> color;
bool isValid(int k, int node, bool graph[101][101], int n){
    for(int i=0; i<n; i++){
        if(k != node && graph[node][i] == true && color[i] == k) return false;
    }
    return true;
}

bool dfs(int node, bool graph[101][101], int m, int n){
    if(node == n) return true;
    
    for(int k=0; k<m; k++){
        if(isValid(k, node, graph, n)){
            color[node] = k;
            if(dfs(node+1, graph, m, n)) return true;
            color[node] = -1;
        }
    }
    
    //All colors were tried but none was valid, so
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    color.resize(n, -1);
    if(dfs(0, graph, m, n)) return true;   
    return false;

}