// 4 Steps to reach desired result.
// I have only mentioned the steps, not the intuition behind those steps, it can be referred here: https://www.youtube.com/watch?v=LuLCLgMElus&t=3s

// Time Complexity:
// 1. Finding breakpoint - O(n)
// 2. Finding element greater than breakpint - O(n)
// 3. Reversing the array - O(n)
// So, overall T.C - O(n)

// Space Complexity: O(1)

void nextPermutation(vector<int>& a) {
	if(a.size() <= 1) return;
	int ind1 =0, ind2=0;

	//1. Find ind1 such that a[ind1] < a[ind1+1]
	for(ind1 = a.size()-2; ind1>=0; ind1--){
		if(a[ind1] < a[ind1+1]) break;
	}

	//If array is in descending order (5,4,3,2,1) -> ind1 will be < 0, i.e. there will be no breakpoint where a[ind] < a[ind+1]. In that case we'll just reverse the array and return. Else we move to step 2.
	
	if(ind1>=0){ 
	//2. Traverse from reverse of array and find element greater than a[ind1]
		for(ind2 = a.size()-1; ind2>ind1; ind2--){
			if(a[ind2]>a[ind1]) break;
		}

		//3. Swap(a[ind1], a[ind2])
		swap(a[ind1], a[ind2]);

		//4. Reverse the array starting from index+1
		reverse(a.begin()+ind1+1, a.end());
	}else{
		reverse(a.begin(),a.end());
	}
	return;
}
