int minSubArrayLen(int k, vector<int>& a) {
	int i=0,j=0,sum=0,minLen = INT_MAX, minLen2 = INT_MAX;
	while(j<a.size()){
		sum += a[j];
		if(a[j] > k) return 1;
		if(sum < k) j++;
		else if(sum == k){
			minLen = min(minLen, j-i+1);
			j++;
		}
		else if(sum > k){
			minLen2 = min(j-i+1,minLen);
			while(sum>k){
				if(sum>=k) minLen2 = min(j-i+1,minLen);
				sum -= a[i];
				i++;
			}
			if(sum == k) minLen = min(j-i+1, minLen);
			minLen = min(minLen, minLen2);
			j++;
		}
	}
	if(minLen == INT_MAX) return 0;
	else return min(minLen,minLen2);
}