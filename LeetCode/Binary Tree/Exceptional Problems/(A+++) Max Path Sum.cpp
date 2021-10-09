int maxPathSum(TreeNode* root) {
	int maxSum = INT_MIN;
	maxPathSumLeftRight(root, maxSum);
	return maxSum;
}
int maxPathSumLeftRight(TreeNode* root, int& maxSum){
	if(!root) return 0;
	int l = maxPathSumLeftRight(root->left, maxSum);
	int r = maxPathSumLeftRight(root->right, maxSum);

	//Temp is the induction step of this problem
	int temp = max(max(l,r) + root->val, root->val);
	int ans = max(temp, l+r+root->val);
	
	maxSum = max(maxSum, ans);
	return temp;
}