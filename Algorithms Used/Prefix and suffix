int sumOfBeauties(vector<int>& a) {
        int n= a.size();
        //This vector will store the minimum element on right side of current element, now the current element could also be the minimum when compared to right side of it, so min(nums[i], minRight[i+1])
        vector<int> minRight(n,0);
        minRight[n-1] = a[n-1];
        
        for(int i=n-2; i>=0; i--){
            minRight[i] = min(a[i], minRight[i+1]);
        }
        //Now for beauty == 2, we need to check whether the current element is maximum element among the elements on its left, no need of seperate array for that, it can be maintained as we traverse through te array.
        int maxLeft = a[0], res = 0;
        for(int i=1; i<n-1; i++){
            if(a[i] > maxLeft && a[i] < minRight[i+1]) res += 2;
            else if(a[i] > a[i-1] && a[i] < a[i+1]) res += 1;
            maxLeft = max(a[i], maxLeft);
        }
        
        return res;
    }