vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& a) {
	vector<int> res;
	vector<int> stack;
	unordered_map<int, int> m;

	for(auto &i:a){
		while(stack.size() && stack.back()<i){
			m[stack.back()] = i;
			stack.pop_back();
		}
		stack.push_back(i);
	}

	for(auto &i:nums1){
		if(m.find(i) != m.end())  i = m[i];
	   else i=-1;
	}
	return nums1;
}