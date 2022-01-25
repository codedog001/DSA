#define psd pair<string, double> 

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<psd>> mp;
        int numOfEquations = equations.size();
        
        for(int i=0; i<numOfEquations; i++){
            string u = equations[i][0], v = equations[i][1];
            double divisionUByV = values[i], divisionVByU = 1/values[i];
            
            mp[u].push_back({v, divisionUByV});
            mp[v].push_back({u, divisionVByU});
        }
        vector<double> result;
        
        for(auto& query:queries){
            string u = query[0], v = query[1];
            double queryResult = -1;
            unordered_set<string> visited;
            if(mp.find(u) != mp.end()){
                double temp = 1;
                dfs(u, v, mp, queryResult, temp, visited);
            }
            result.push_back(queryResult);
        }
        return result;
    }
};

void dfs(string u, string v, unordered_map<string, vector<psd>> mp, double& ans, double temp, unordered_set<string>& visited){
        if(visited.find(u) != visited.end()) return;
        
		//Mark current node as visited
        visited.insert(u);
		
		//Current node is result node, i.e. temp is holding desired answer
        if(u == v){
            ans = temp;
            return;
        }
        
		//Visit neighboring nodes
        vector<psd> t = mp[u];
        for(auto &p:t){
            string d = p.first;
            double div = p.second, temp2 = temp;
			
			//Multiply current division to temp
            temp = temp * div;
            dfs(d, v, mp, ans, temp, visited);
            
            //Reset temp, as result was not found in this path
            temp = temp2;
        }
    }