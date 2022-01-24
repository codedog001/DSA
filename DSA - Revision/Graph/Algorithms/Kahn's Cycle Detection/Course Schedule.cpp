// Logic: If course 0 depends on 1, 1 depends on 2, and 2 depends on 0, there exists a cycle, and required number of courses can't be completed.

1. Cycle Detection using DFS:

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> dirAdj[n], visited(n,0), curCallVisited(n,0);
        
		//Create an adjacency matrix from given array
        for(auto& pairCourse: prerequisites){
            int u = pairCourse[0], v = pairCourse[1];
            dirAdj[u].push_back(v);
        }
        
		//Detect cycle
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                if(containsCycleDFS(i, dirAdj, n, visited, curCallVisited)) return false;
            }
        }
        return true;
    }
    
    bool containsCycleDFS(int node, vector<int> dirAdj[], int n, vector<int>& visited, vector<int>& curCallVisited){
        visited[node] = 1;
        curCallVisited[node] = 1;
        
        vector<int> neighbors = dirAdj[node];
        
        for(auto& num:neighbors){
            if(visited[num] == 0){
                if(containsCycleDFS(num, dirAdj, n, visited, curCallVisited)) return true;
            }
            else if(curCallVisited[num] == 1) return true;
        }
        curCallVisited[node] = 0;
        return false;
    }
};
2. Cycle Detection using BFS: Kahn's Algorithm

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> dirAdj[n];
        //Create adj. matrix
        for(auto& pairCourse: prerequisites){
            int u = pairCourse[0], v = pairCourse[1];
            dirAdj[u].push_back(v);
        }
        
        //Check whether graph contains cycle using Kahn's algo
        if(kahnsAlgoToFindCycle(dirAdj, n)) return false;
        return true;
    }
    
    bool kahnsAlgoToFindCycle(vector<int> dirAdj[], int n){
        vector<int> inDegree(n,0), result;
        //Store indegree of all nodes
        for(int i=0; i<n; i++){
            vector<int> t = dirAdj[i];
            for(auto& num:t){
                inDegree[num]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vector<int> neighbors = dirAdj[node];
            result.push_back(node);
            
            for(auto& num: neighbors){
                inDegree[num]--;
                if(inDegree[num] == 0) q.push(num);
            }
        }
        
        //If graph contains cycle result will have < n elements
        int resultSize = result.size();
        if(resultSize < n) return true;
        return false;
    }
};