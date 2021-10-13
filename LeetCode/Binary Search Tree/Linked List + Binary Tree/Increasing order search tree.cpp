//Using inorder traversal
TreeNode* increasingBST(TreeNode* root) {
	if(!root) return NULL;
	stack<TreeNode*> s;
	auto node = root;
	auto n1 = new TreeNode(0);
	
	//head is a sentinel node
	auto head = n1;
	while(node || !s.empty()){
		while(node){
			s.push(node);
			node = node -> left;
		}
		node = s.top();
		s.pop();
		auto n2 = new TreeNode(node->val);
		n1 -> right = n2;
		n1 = n1->right;
		node = node -> right;
	}
	n1->right = NULL;
	return head->right;
}