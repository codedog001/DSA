double myPow(double x, int n) {
	double res = 1;
	long long nn = n;
	if(nn<0) nn= -1 * nn;
	while(nn!=0){
		if(nn%2!=0){
			res = res * x;
			nn = nn- 1;
		}
		//This is where we reduce no. of operations by by squaring x and dividing nn 2, instead of reducing by 1.
		else{
			x = x*x;
			nn = nn/2;
		}
	}
	if(n<0) res = (1.0)/(res);
	return res;
}