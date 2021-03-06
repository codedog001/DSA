bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) return sum-root->val == 0;
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }