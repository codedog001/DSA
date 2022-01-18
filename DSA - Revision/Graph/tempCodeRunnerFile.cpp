nt adjacency list
    for(int i=1; i<=n; i++){
        vector<int> p = adj[i];
        cout << "Node: " << i << " has edge with ";
        for(auto &num:p) cout<< num << " ";
        cout << endl;
    }