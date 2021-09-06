class Solution {
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int>dis;
        vector<vector<int>> res;
        multimap<int, int> m;
        
     for(int i=0;i<points.size();i++){
         int x2 = points[i][0];
         int y2 = points[i][1];
         int disSq = (x2*x2) + (y2*y2);
         m.insert({ disSq, i });
         
     }   
    
    for(auto it = m.begin(); K>0; ++it,K--){
        res.push_back(points[it->second]);
    }
        return res;
    }
};