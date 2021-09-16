vector<vector<int>> merge(vector<vector<int>>& a) {
	vector<vector<int>> res;
	if(a.size()==0) return res;
	if(a.size() ==1) return a;

	sort(a.begin(), a.end());

	//After Sorting -> a: [[1,3],[2,6],[8,10],[15,18]]

	vector<int> curInt = a[0]; //[1,3]

	//We push interval in output vector, then compare it next intervals to see if overlap exists. Starting from first interval => a[0]
	res.push_back(curInt); //[[1,3]]

	for(auto & v: a){
		//Curbegin and curend are begin and end of the interval present in output array.
		int curBegin = curInt[0]; //1
		int curEnd = curInt[1]; //3
		
		//NextBegin and NextEnd are begin and end of interval we are comparing with in curBegin and curEnd.
		int nextBegin = v[0]; //2
		int nextEnd = v[1]; //6
		
		//True Overlapping condition
		if(curEnd >= nextBegin) {
			curInt[1] = max(nextEnd, curEnd); //[1,6]
			res.pop_back();
			res.push_back(curInt); //[[1,6]]
		}
		//If not an overlap, then it is a new interval
		else{ //Consider [1,6] and [8,10]
			curInt = v; //[8,10] is the new curInt
			res.push_back(curInt); //[[1,6], [8,10]]
		}
	}
	return res;
}