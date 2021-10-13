1. Recursive:

    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val == val) return root;
        if(root->val < val){
            auto right = searchBST(root->right, val);
            if(right) return right;
        }
        else{
            auto left = searchBST(root->left, val);
            return left;
        }
        return NULL;
    }

    
2. Iterative:

TreeNode* searchBST(TreeNode* root, int val) {
    while (root  && root->val != val) {
      if(root->val > val) root= root->left;
	  else root = root->right;
    }
    return root;
}