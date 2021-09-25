One of the solutions in discuss suggested that this question is basically finding longest substring with at most k no. of zeros, and it works.

int longestOnes(vector<int>& a, int k) {
	int zero = 0, i = 0, maxLen = 0;
	for(int j = 0 ; j < a.size() ; j++) {
		if( a[j] == 0 ) zero+=1;
		while(zero > k) {
			if(a[i] == 0) zero-=1;
			i++;
		}
		maxLen = max( maxLen, j-i+1);
	}
	return maxLen;
}