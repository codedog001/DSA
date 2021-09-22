    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> d;
        vector<int> res;
        int i=0,j=0;
        
        while(j<a.size()){
            //1.Calculation
            while(d.size() && a[j] > d.back()) d.pop_back();
            d.push_back(a[j]);
            
            
            //2. Move j
            if(j-i+1 < k) j++;
            
            //3. Slide window
            else if(j-i+1 == k){
                //i. Get answer from calculation
                res.push_back(d.front());
                
                //ii. Remove i from calculation
                if(d.front() == a[i]) d.pop_front();
                
                //iii. Slide Window
                i++;
                j++;
            }
        }
        return res;
    }