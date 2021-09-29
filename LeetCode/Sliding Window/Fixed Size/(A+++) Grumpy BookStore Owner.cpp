// At the core of the question, it is asking to count maximum unsatisfied people in the window of size k (k=minutes in this case).

// Why?
// Becuase the minutes where behavior can be tricked can be used consecutively, now satisfied customers will always be satisfied so they are directly added, in that particular minutes window, if the number of unsatisfied customers are largest then the total sum at the end would be the largest.

int maxSatisfied(vector<int>& a, vector<int>& g, int k) {
	int i=0, j=0, satisfied = 0, unsatisfied = 0, maxUnsatisfied = 0;
	while(j<g.size()){
	//As I said earlier, satisfied is the number we can directly add to result.
		if(g[j] == 0) satisfied += a[j];
		else unsatisfied += a[j];

		if(j-i+1 < k) j++;

		else if(j-i+1 == k){
			//Get answer from calculation
			//Unsatisfied within a particular window is the number of customers, we want to be maximum so that overall sum can increase.
			maxUnsatisfied = max(unsatisfied, maxUnsatisfied);

			//Remove unsatisfied i from the window as we slide it further.
			unsatisfied -= g[i] * a[i];

			//Slide Window
			i++;
			j++;
		}
	}
	return satisfied + maxUnsatisfied;
}