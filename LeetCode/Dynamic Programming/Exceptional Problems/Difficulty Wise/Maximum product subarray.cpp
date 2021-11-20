1. Saving results in array:

    int maxProduct(vector<int>& a) {
        vector<int> maxValue(a.size()), minValue(a.size());
        maxValue[0] = minValue[0] = a[0];
        
        for(int i=1; i<a.size(); i++){
            maxValue[i] = max(maxValue[i-1] * a[i], max(minValue[i-1] * a[i], a[i]));
            minValue[i] = min(minValue[i-1] * a[i], min(maxValue[i-1] * a[i], a[i]));
        }
        
        int res = INT_MIN;
        for(auto& n:maxValue){
            res = max(res, n);
        }
        return res;
    }
2. Save some space: Saving results in variable

int maxProduct(vector<int>& a) {
        int maxValue= a[0], minValue = a[0];
        int res = maxValue;
        
        for(int i=1; i<a.size(); i++){
            int temp = maxValue;
            maxValue = max(temp * a[i], max(minValue * a[i], a[i]));
            minValue = min(minValue * a[i], min(temp * a[i], a[i]));
            
            res = max(res, maxValue);
        }
        return res;
    }