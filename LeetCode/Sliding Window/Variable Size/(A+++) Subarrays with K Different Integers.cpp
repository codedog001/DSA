// A++++++ Problem Exactly of sliding window
// Similar Problem: Count nice subarrays.

Exactly = atMostK(k) - atMostK(k-1)

int atMostK(vector<int>& a, int k) {
        int i=0,count = 0,res =0;
        unordered_map<int,int> m;
        for(int j=0;j<a.size();j++){
            m[a[j]]++;
            if(m[a[j]]==1) count++;
            if(count > k){
                while(count>k){
                    m[a[i]]--;
                    if(m[a[i]] == 0) count--;
                    i++;
                }
            }
            res += j-i+-1;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return atMostK(a,k) - atMostK(a,k-1);
    }