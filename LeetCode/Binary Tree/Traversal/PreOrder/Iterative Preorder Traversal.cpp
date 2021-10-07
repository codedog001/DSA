vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	if(!root) return res;
	stack<TreeNode*> s;
	s.push(root);

	auto node = root;
	while(!s.empty()){
		node = s.top();
		s.pop();
		res.push_back(node->val);

		if(node -> right) s.push(node->right);
		if(node -> left) s.push(node->left);
	}
	return res;
}