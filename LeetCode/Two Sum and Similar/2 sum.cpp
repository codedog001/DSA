vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	unordered_map<int, int> m;
	for(int i=0; i<nums.size(); i++){
		int numToFind = target - nums[i];
		if(m.find(numToFind) != m.end()){
			res.push_back(m[numToFind]);
			res.push_back(i);
			break;
		}
		m[nums[i]] = i;
	}
	return res;
}