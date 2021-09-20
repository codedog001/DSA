int maxLen(vector<int>&a, int n)
    {   
        unordered_map<int,int> m;
        int maxi = 0;
        int sum = 0;
        
        for(int i=0; i<a.size(); i++){
            sum += a[i];
            if(sum==0) maxi=i+1;
            else{
                if(m.find(sum) != m.end()) {
                //Sum is repeating, i.e. the elements in the window b/w m[sum] and element at index i (including i), have sum = 0.
                    maxi = max(maxi, i-m[sum]);
                }
                else{
                    m[sum] = i;
                }
            }
        }
        return maxi;
    }