vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(!root) return res;
        auto node = root;
        
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node -> left;
            }
            node = s.top();
            res.push_back(node->val);
            s.pop();
            node = node -> right;
        }
    return res;
    }