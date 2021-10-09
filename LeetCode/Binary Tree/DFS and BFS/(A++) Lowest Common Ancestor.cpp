//Using DFS
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val) return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(!l && !r) return NULL;
        if(l && r) return root;
        if(!l) return r;
        if(!r) return l;
        
        //Code never runs here:
        return NULL;
    }