class Solution {
public:
    bool isValid(int n, long long mid, vector<int>& batteries){
        long long totalBatteryNeeded = n * mid;
        long long sum = 0;
        for(long long num:batteries){
            sum += min(num, mid);
            if(sum >= totalBatteryNeeded) return true;
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        if(batteries.size() < n) return 0;
        
        long long no = batteries.size(), low = 0, high = 0, sum = 0, result = 0;
        sort(batteries.begin(), batteries.end());
        
        for(auto& num:batteries) sum += num;
        
        //high = sum is also correct, but more precisely a single computer maximum can get
        //sum/n
        high = sum/n, low = 0;
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isValid(n, mid, batteries)){
                result = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        
        return result;
    }
};