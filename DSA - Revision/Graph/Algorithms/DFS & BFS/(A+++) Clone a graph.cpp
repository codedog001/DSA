Note:

Map stores the {Original Node: Copy Node} mapping, rest is intuitive as you go through the code. Since hashmap is hashing nodes instead of node->val, duplicates are handled.
I believe that you have good understanding of plane and simple BFS and DFS traversal of graph, and then attempting this problem.
Dry run this code, maybe multiple times, it took me 2 hours to implement this problem, once you understand it, it is pretty straight forward to code either using BFS or DFS, I suggest to implement it in both BFS and DFS for a better understanding.
1. DFS:

class Solution {
public:
    Node* cloneGraph(Node* node){
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        return dfsToCloneGraph(node, mp);
    }
    
    Node* dfsToCloneGraph(Node* node, unordered_map<Node*, Node*>& mp){
        if(!node) return NULL;
        vector<Node*> neighborVector = node -> neighbors;        
        auto copyNode = new Node(node->val);
        mp[node] = copyNode;
        
        for(auto& neighbor: neighborVector){
            if(mp.find(neighbor) == mp.end()){
                //Call dfs
                auto copyRef = dfsToCloneGraph(neighbor, mp);
                copyNode->neighbors.push_back(copyRef);
            }
            else if(mp.find(neighbor) != mp.end()){
                copyNode->neighbors.push_back(mp[neighbor]);
            }
        }
        return copyNode;
    }
};
2. BFS:

class Solution {
public:
    Node* result = NULL;
    Node* cloneGraph(Node* node){
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        return bfsToCloneGraph(node, mp);
    }
    
    Node* bfsToCloneGraph(Node* node, unordered_map<Node*, Node*>& mp){
        if(!node) return NULL;
        auto copyNode = new Node(node->val);
        mp[node] = copyNode;
        
        queue<Node*> q;
        q.push(node);
        result = copyNode;
        
        while(!q.empty()){
            Node* thisNode = q.front();
            q.pop();
            vector<Node*> neighborVector = thisNode -> neighbors;  
            auto curNodeCopy = mp[thisNode];
            
            for(auto& neighbor: neighborVector){
                if(mp.find(neighbor) == mp.end()){
                    auto copyOfNeighborNode = new Node(neighbor -> val);
                    mp[neighbor] = copyOfNeighborNode;
                    curNodeCopy -> neighbors.push_back(copyOfNeighborNode);
                    q.push(neighbor);
                }
                else if(mp.find(neighbor) != mp.end()){
                    curNodeCopy -> neighbors.push_back(mp[neighbor]);
                }
            }
        }
        return result;
    }
};