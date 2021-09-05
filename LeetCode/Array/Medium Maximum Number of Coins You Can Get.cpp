class Solution {
public:
   
    
    int maxCoins(vector<int>& p) {
        int res = 0;
        sort(p.begin(),p.end());
        for(int i=p.size()/3; i<p.size(); i+=2){
            res+=p[i];
        }
        return res;
    }
};