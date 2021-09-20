vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
	//nums: [8,1,2,2,5,3]
	vector<int> copy(nums);

	sort(copy.begin(), copy.end());
	//copy: [1,2,2,2,5,8]

	unordered_map<int,int> m;

	//We are mapping element num to number of elements smaller than num.
	//m[4] is 5, so there are 4 elements smaller than 5.
	//That is if an element is at index i, there are i elements that are smaller than it.

	//Loop stops at 1 because element at 0th index doesn't have any element smaller than it in a sorted array.

	for(int i=copy.size()-1; i>=1; i--){
		if(copy[i] != copy[i-1]){
			int num = copy[i];
			m[num] = i;             
		}
	}

	//Now for each key in map, change corresponding value in nums
	for(auto &g:nums){
		g = m[g];
	}
	return nums;
}