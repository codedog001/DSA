    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        
        int left = rangeSumBST(root->left, low, high);
        int right = rangeSumBST(root->right, low, high);
        
        if(root->val >= low && root->val<=high) return root->val + left + right;
        else return left+right;
    }