    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val == q->val){
            if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) return true;
        } 
        return false;
    }