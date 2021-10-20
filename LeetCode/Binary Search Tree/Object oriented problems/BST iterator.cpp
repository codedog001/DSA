stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        auto node = root;
        while(node){
            s.push(node);
            node=node->left;
        }
    }
    
    int next() {
        auto top = s.top();
        s.pop();
        
        auto right = top->right;
        while(right){
            s.push(right);
            right = right->left;
        }
        return top->val;
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        return false;
    }