int shortestSubarray(vector<int>& arr, int sum) {
    deque<int> d;
    int ans = INT_MAX, n = arr.size();
    
	for(int i = 1; i<n; i++){
		arr[i] += arr[i - 1];
	}
	
    for(int i = 0; i<n; i++){
        if(arr[i] >= sum){
            ans = min(ans, i+ 1);
        }
        while(!d.empty() && arr[i] - arr[d.front()] >= sum){
            ans = min(ans, i - d.front());
            d.pop_front();
        }
        while(!d.empty() && arr[i] <= arr[d.back()]){
            d.pop_back();
        }
        d.push_back(i);
    }
    return ans == INT_MAX ? -1 : ans;
}