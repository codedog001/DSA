double findMaxAverage(vector<int>& a, int k) {
	int i=0,j=0;
	double avg = INT_MIN, sum = 0;
	while(j<a.size()){
		//1. Calculation
		sum += a[j];

		//2. Move j
		if(j-i+1 < k) j++;

		//3. When window size is reached
		else if(j-i+1 == k){
			//1. Get result from calculation
			double curAvg = sum/k;
			avg = max(curAvg, avg);

			//2. Remove i from calc.
			sum -= a[i];

			//3. Move i and j (slide window)
			i++;
			j++;
		}
	}
	return avg;
}