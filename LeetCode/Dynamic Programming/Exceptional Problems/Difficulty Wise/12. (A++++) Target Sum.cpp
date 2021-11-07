Logic: This problem is finding S1-S2 = target, consider S1 a subset that is taken with positive sign (+), and S2 the subset with negative sign (-).
Sum being the net sum of all elements, we need to find S1 such that
S1 = (sum - target)/2
If S1 exists, the remaining subset has sum S2 inevitably.
The number of subsets that can be found with sum S1, is the answer for this problem.

If you understand the logic that why we are counting subsets with sum S1, writing code is the easiest thing, logic is most important. Also, more is explained in comments as and when needed.

int findTargetSumWays(vector<int>& nums, int target) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	
	//For below if condition, 
	//sum<abs(target), consider test case - nums: [100], target: -200
	//(target+sum) % 2 != 0, consider test case - nums: [7,9,3,8,0,2,4,8,3,9], its sum = 53 and target: 0, there could not be any 26.5 in integer array.
	
	if(sum < abs(target) || (target+sum) %2 != 0) return 0;
	
	//S1 is newTarget
	int newTarget = (sum - target)/2;
	return countSubsetsWithSumTarget(nums, newTarget);
}

//Count subsets with sum S1
int countSubsetsWithSumTarget(vector<int>& a, int target){
	int n= a.size(), w = target;
	int t[n+1][w+1];

	//Initialization
	for(int i=0; i<w+1; i++) t[0][i] = 0;
	for(int j=0; j<n+1; j++) t[j][0] = 1;

	//Knapsack 01
	for(int i=1; i<n+1; i++){
	
	//j starts from 0, becuase 0s are considered valid in this problem, e.g - nums: [0,0,0,0], target: 0, ans = 16
		for(int j=0; j<w+1; j++){
			if(a[i-1] <= j){
				t[i][j] = t[i-1][j-a[i-1]] + t[i-1][j];
			}else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][w];
}