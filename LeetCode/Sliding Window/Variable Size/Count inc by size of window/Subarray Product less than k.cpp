int numSubarrayProductLessThanK(vector<int>& a, int k) {
	int i=0,j=0,n=a.size(),mul=1,res = 0;
	if(k==0) return 0;
	for(j=0; j<n ;j++){
		mul *= a[j];
		if(mul >=k){
			while(i<=j && mul>=k){
				mul /= a[i];
				i++;
			}
		}
	   res+=j-i+1;
	}
	return res;
}