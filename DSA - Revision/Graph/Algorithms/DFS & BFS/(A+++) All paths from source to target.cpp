//Explanation of T.C, S.C: https://leetcode.com/problems/all-paths-from-source-to-target/discuss/1599683/C%2B%2BPython-Simple-Solution-w-Explanation-or-BFS-and-DFS-Traversals
1. DFS: 
// T.C: O(N*2^N)
// S.C: O(N)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size(), source = 0, destination = n-1;
        vector<int> temp;
        vector<vector<int>> result;
        dfs(source, destination, n, graph, result, temp);
        return result;
    }
    
    void dfs(int node, int dest, int n, vector<vector<int>>& adjList, vector<vector<int>>& result, vector<int>& temp){
	//Insert current node into temp
        temp.push_back(node);
		
	//Base case: current node is destination
        if(node == dest){
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        auto neighbors = adjList[node];
		
        for(auto& neighbor: neighbors){
		//Call DFS on nodes that have not yet been visited
            dfs(neighbor, dest, n, adjList, result, temp);
        }
		
		//Backtrack:
        temp.pop_back();
    }
};
2. BFS:
// T.C: O(N*2^N)
// S.C: O(N*2^N)

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size(), source = 0, destination = n-1;       
        vector<vector<int>> result;
        bfs(source, destination, n, graph, result);
        return result;
    }
    
    void bfs(int source, int dest, int n, vector<vector<int>>& adjList, vector<vector<int>>& result){
        
	    //Insert current node into temp
        vector<int> temp;
        temp.push_back(source);
        queue<vector<int>> q;
        q.push({source});
		
        while(!q.empty()){
            vector<int> path = q.front();
            q.pop();
            if(path.back() == dest){
                result.push_back(path);
            }
            else{
                vector<int> neighbors = adjList[path.back()];
                for(auto& neighbor: neighbors){
                    path.push_back(neighbor);
                    q.push(path);
                    path.pop_back();
                }
            }
        }
    }
};