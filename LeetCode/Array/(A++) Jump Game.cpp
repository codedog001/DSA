bool canJump(vector<int>& a) {
	int reach =0,i=0;
	for(i=0; i<=reach; i++){
		reach = max(i+a[i], reach);
		if(reach >= a.size()-1) return true;
	}
	return false;
}