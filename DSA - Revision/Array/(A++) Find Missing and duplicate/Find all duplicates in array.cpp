//Leetcode Medium: https://leetcode.com/problems/find-all-duplicates-in-an-array/
//Basic swap sort

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int i=0, n= a.size();
        while(i<n){
            if(a[i] != a[a[i]-1]) swap(a[i], a[a[i]-1]);
            else i++;
        }
        
        vector<int> res;
        for(i=0; i<n; i++){
            if(a[i] != i+1) res.push_back(a[i]);
        }
        return res;
    }
};