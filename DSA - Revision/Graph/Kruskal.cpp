#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int u;
    int v;
    int w;

    Node(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int findParent(int node, vector<int>& parent){
    if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionParents(int parU, int parV, vector<int>& parent, vector<int>& rank){

    if(rank[parU] < rank[parV]){
        parent[parU] = parV;
    }
    else if(rank[parV] < rank[parU]){
        parent[parV] = parU;
    }
    else if(rank[parV] == rank[parU]){
        //Any node could become parent of other node
        parent[parU] = parV;
        rank[parV]++;
    }
}

static bool comp(Node& a, Node& b){
    return a.w < b.w;
}

int main(){
    vector<Node> edges;
    int n, e;
    cin >> n >> e;

    //Graph input can't be in adjacency list, since it can't be sorted.

    //1. Take input of graph.
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Node newNode(u,v,w);
        edges.push_back(newNode);
    }

    //2. Sort in increasing order of weight.
    sort(edges.begin(), edges.end(), comp);


    //3. Create parent vector
    vector<int> parent(n,0);

    //4. Make each node its own parent
    for(int i=0; i<n; i++) parent[i] = i;

    //5. Create rank vector and result vector mst containing node:parent pair
    vector<int> rank(n,0);
    vector<Node> result;

    //6. Traverse the edges vector
    for(auto &curEdge: edges){
        //7. If the two nodes don't belong to same component, which means they don't
        //have same parent, then we will add them to MST, because if two nodes which belonged
        //to same component are connected then it will introduce cycle in the MST.
        int u = curEdge.u, v = curEdge.v;
        int parU = findParent(u, parent);
        int parV = findParent(v, parent);
        
        if(parU != parV){
            result.push_back(Node(u, v, curEdge.w));
            //Union operation makes parents of both nodes same
            unionParents(parU, parV, parent, rank);
        }
    }
    //Print result
    int totalWeight = 0;
    for(auto& e:result){
        cout << "Node " << e.u << " is connected to " << e.v << ". Edge Weight: " << e.w << endl;
        totalWeight += e.w;
    }
    cout << "Total Weight is: " << totalWeight << endl;

}