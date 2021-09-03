class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        //Distance of centre to point
        //disSq = (x2-x1)^2 + (y2-y1)^2
        //dis = pow(disSq,1/2);
        //x1,y1 = Circle Coordinates
        //x2,y2 = point coordinates.
        
        vector<int> res(queries.size(),0);
        
        for(int i=0;i<queries.size();i++){
            int x1 = queries[i][0];
            int y1 = queries[i][1];
            int radSq = queries[i][2] * queries[i][2] ;
            
            for(int j=0; j<points.size();j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int disX = (x2-x1);
                int disy = (y2-y1);
                int disSqX = pow(x2-x1,2);
                int disSqY = pow(y2-y1,2);
                int disSq = disSqX + disSqY;
                
                
                if(disSq<=radSq){
                    res[i]+=1;
                }
            }
        }
        
        return res;
    }
};