//Using Moore's voting algorithm
    //maj1 and maj2 - There could be maximum of 2 elements that have occurence > N/3.
    
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int maj1 = -1, maj2 = -1, c1 = 0, c2 = 0;
        for(auto & n:nums){
            if(n == maj1) c1++;
            else if(n == maj2) c2++;
            else if(c1 == 0) {
                maj1 = n;
                c1 = 1;
            }
            else if(c2 == 0) {
                maj2 = n;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        //Now, if any of maj1 or maj2 occurs lesser than N/3 times, for eg: only one element is majority element, then one of them will be storing value that is not a vaid answer, it can't be stored in res array.
        //Check if maj1 and maj2 occur more than N/3 times in the array. 
        
        c1=0,c2=0;
        for(auto n:nums){
            if(n==maj1) c1++;
            else if(n==maj2)c2++;
        }
        
        int len = nums.size();
        //Now store elements having > N/3 occurences.
        if(c1>len/3) res.push_back(maj1);
        if(c2>len/3) res.push_back(maj2);
        return res;
    }