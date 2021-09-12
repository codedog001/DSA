vector<int> finalPrices(vector<int>& p) {
	vector<int> stack;
	for(int i=0; i<p.size(); i++){
		while(stack.size() && p[stack.back()] >= p[i]){
			p[stack.back()] -= p[i];
			stack.pop_back();
		}
		stack.push_back(i);
	}
	return p;
}