// Make sure you're passing variables by reference to helper function, otherwise last test case will give TLE.

TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
	map<int, int> m;
	for(int i=0; i<in.size(); i++) m[in[i]] = i;
	TreeNode* root = helper(pr, 0, pr.size()-1, in, 0, in.size()-1, m);
	return root;
}

TreeNode* helper(vector<int>& pr, int preStart, int preEnd, vector<int>& in, int inStart, int inEnd, map<int, int>& m){
	if(preStart > preEnd || inStart > inEnd) return NULL;
	TreeNode* root = new TreeNode(pr[preStart]);

	int rootIdx = m[root->val];

	int numsOnLeft = rootIdx - inStart;
	root-> left = helper(pr, preStart+1, preStart+numsOnLeft, in, inStart, rootIdx-1, m);
	root-> right = helper(pr, preStart+1+numsOnLeft, preEnd, in, rootIdx+1, inEnd, m);

	return root;
}
// Reference: https://www.youtube.com/watch?v=aZNaLrVebKQ&t=0s