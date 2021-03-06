class Solution {
public:
    bool isValid(int n, long long mid, vector<int>& batteries){
        long long totalBatteryNeededForAllCompToRunAtMid = n * mid;
        long long sum = 0;
        for(long long num:batteries){
            sum += min(num, mid);
            if(sum >= totalBatteryNeededForAllCompToRunAtMid) return true;
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        if(batteries.size() < n) return 0;
        long long no = batteries.size(), minBatteryACompCanGet = 0, maxBatteryACompCanGet = 0, sum = 0, result = 0;
        sort(batteries.begin(), batteries.end());
        for(auto& num:batteries) sum += num;
        
        //high = sum is also correct, but more precisely a single computer maximum can get
        //sum/n
        maxBatteryACompCanGet = sum/n, minBatteryACompCanGet  = 0;
        while(minBatteryACompCanGet <= maxBatteryACompCanGet){
            long long mid = minBatteryACompCanGet + (maxBatteryACompCanGet - minBatteryACompCanGet)/2;
            if(isValid(n, mid, batteries)){
                result = mid;
                minBatteryACompCanGet = mid + 1;
            }else maxBatteryACompCanGet = mid - 1;
        }
        return result;
    }
};




