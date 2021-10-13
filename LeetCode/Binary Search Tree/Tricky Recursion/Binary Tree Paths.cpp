void helper(vector<string>& res, TreeNode* root, string str){
	if(!root->left && !root->right){
		res.push_back(str);
		return;
	}
	string leftStr = str;
	string rightStr = str;

	if(root->left){
		leftStr += "->" + to_string(root->left->val);
		helper(res, root->left, leftStr);
	}
	if(root->right){
		rightStr += "->" + to_string(root->right->val);
		helper(res, root->right, rightStr);
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;
	if(!root) return res;
	string str = to_string(root->val);
	helper(res, root, str);
	return res;
}