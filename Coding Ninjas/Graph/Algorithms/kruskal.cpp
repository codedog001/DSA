#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int v1;
    int v2;
    int w;
    
    Edge(int a, int b, int w){
        v1 = a;
    	v2 = b;
        this->w = w;
    }
};

int findParent(int v, vector<int>& parent){
    if(v == parent[v]) return v;
    return findParent(parent[v], parent);
}


bool notAddsCycle(Edge e, vector<int>& parent){
    //Check if this edge will add cycle
    int ov1 = e.v1, ov2 = e.v2, parent1 = parent[e.v1], parent2 = parent[e.v2];
        
    //Find parent of v1 and v2
    parent1 = findParent(e.v1, parent);
    parent2 = findParent(e.v2, parent);
        
    if(parent1 != parent2){
        parent[ov2] = parent1;
        return true;
    }
    return false;
}

bool customSort(Edge& a, Edge& b){
    if(a.w!=b.w) return a.w < b.w;
    else if(a.w == b.w){
        if(a.v1 != b.v1) return a.v1 < b.v1;
        else return a.v2 < b.v2;
    } 
}

int main() {
    
    //Step 1: Take input of graph in vector<edge>
    
    int n, e;
    cin >> n >> e;
    vector<Edge> a; //Size will be e
    
    for(int i=0; i<e; i++){
		int x, y, z;
        cin >> x >> y >> z;
        if(x>y) swap(x,y);
        Edge t(x,y,z);
        a.push_back(t);
    }
    
    
    //Step 2: Sort that graph by increasing order of weight.
    sort(a.begin(), a.end(), customSort);

    //Step 3: Pick n-1 edges greedily from the vector 'a' and store an edge in output
    //vector<edge> if it doesn't  introduce cycle in the graph.
    
    //i. Next is to code a checking function that tells whether current  edge adds a 
    //cycle in graph - Union Find
    
    vector<int> parent(n,0);
    for(int i=0;i<n; i++) parent[i] = i;
    
    vector<Edge> res; //Size will be n-1.
    
    //ii. If edge does not introduce cycle, add it to result.
    for(auto c:a){
        if(notAddsCycle(c, parent) && res.size() < n-1) res.push_back(c);
    }
        
    for(auto &c:res){
        cout << c.v1 << " " << c.v2 << " " << c.w << endl;
    }
}

