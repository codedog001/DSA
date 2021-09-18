/Logic: Moore's voting algorithm
int majorityElement(vector<int>& a) {
        int majority = 0, count=0;
        for(auto num:a){
            if(count == 0) majority = num;
            if(num == majority) count++;
            else if(num != majority) count--;
        }
        return majority;
    }