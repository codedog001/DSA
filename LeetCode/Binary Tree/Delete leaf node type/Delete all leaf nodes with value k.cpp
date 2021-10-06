TreeNode* removeLeafNodes(TreeNode* root, int t) {
	if(!root) return NULL;

	root->left = removeLeafNodes(root->left,t);
	root->right = removeLeafNodes(root->right,t);

	if(!root->left && !root->right && root->val==t) return NULL;

	return root;
}