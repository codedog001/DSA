bool checkInclusion(string s1, string a) {
	int i=0, j=0;
	unordered_map<char,int> m;

//Store frequency of all characters of s1 in map.
	for(auto &c: s1) m[c]++;
	
	//Count stores the no. of unique characters in s1.
	int count = m.size();

	while(j<a.size()){
	
	//If we find same character as in map reduces its frequency.
		if(m.find(a[j]) != m.end()) {
			m[a[j]]--;
			if(m[a[j]] == 0) count--;
		}
		
		//While size of substring and s1 doesn't match, keep moving j, i.e. increase the size of substring.
		if(j-i+1 < s1.size()) j++;
		
		//When size matches, we need to check if count has reached zero, if yes then permutation is found.
		else if(j-i+1 == s1.size()){
			if(count == 0) return true;
			
			//If size is same but permutation is not found, we slide the window and restore frequency of a[i] in map, as it is no longer part of substring.
			else{
				if(m.find(a[i]) != m.end()) {
					m[a[i]]++;
					if(m[a[i]] == 1) count++;
				}
				i++;
				j++;
			}
		}              
	}
	return false;
}