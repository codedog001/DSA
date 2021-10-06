vector<int> findDuplicates(vector<int>& a) {
	vector<int> res;
	int i=0;

	while(i<a.size()){
		if(a[i]!=a[a[i]-1]) swap(a[i], a[a[i] - 1]);
		else i++;
	}
	i=0;
	while(i<a.size()){
		if(a[i]!=i+1) res.push_back(a[i]);
		i++;
	}
	return res;
}