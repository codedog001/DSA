1. Using 2 stacks

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;
	if(!root) return res;

	stack<TreeNode*> s1, s2;
	s1.push(root);
	while(!s1.empty()){
		root = s1.top();
		s1.pop();
		s2.push(root);

		if(root -> left) s1.push(root->left);
		if(root -> right) s1.push(root->right);
	}
	while(!s2.empty()) {
		res.push_back(s2.top()->val);
		s2.pop();
	}
	return res;
}
2. Using 1 Stack

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        auto node = root;
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node->left;
            }
            auto temp = s.top()->right;
            if(temp) node = temp;
            
            //Both Left and right of current node are null so push this node to result.
            else{
                temp = s.top();
                res.push_back(temp->val);
                s.pop();
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    res.push_back(temp->val);
                }
            }
        }
        return res;
    }