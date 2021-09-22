vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    int i=0,j=0;
    vector<long long> res;
    deque<int> d;
    while(j<n){
        //1. Calculation
        if(a[j] < 0) d.push_back(a[j]);
        
        //2. If window size not reached move j
        if(j-i+1 < k) j++;
        
        //3. When window size is reached
        else if(j-i+1 == k){
            
            //i. Get answer from calculation
            if(d.empty()) res.push_back(0);
            else res.push_back(d.front());
            
            //ii. Remove i from calculation
            if(a[i] == d.front()) d.pop_front();
            
            //iii. Slide window
            i++;
            j++;
        }
    }
    return res;
    
}