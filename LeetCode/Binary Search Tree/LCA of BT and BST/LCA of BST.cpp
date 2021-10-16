
//Logic: The key is, when p and q are on other side of current node, then the current node
// will be the LCA, if current node is not LCA, p and q will always be on same side of 
// current node.

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        
        else return root;
        
        //Code never runs here
        return NULL;
    }