class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        a.push_back({1});
        
        for(int i=2; i<=numRows; i++){
            vector<int> b;
            int sizeOfb = i;
            b.resize(sizeOfb,0);
            b[0] = 1;
            b[sizeOfb-1] = 1;
            
            vector<int> prevVector = a[i-2];
            int sizeOfPrevVector = i-1;
            
            for(int j=1; j<sizeOfPrevVector; j++){
                b[j] = prevVector[j-1] + prevVector[j];
            }
            
            a.push_back(b);
        }
        
        return a;
    }
};