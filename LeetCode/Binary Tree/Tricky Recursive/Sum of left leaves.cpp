    void sumHelper(TreeNode* root, int& sum){
        if(!root) return;
        sumHelper(root->left,sum);
        if(root->left && !root->left->left && !root->left->right) sum+=root->left -> val;
        sumHelper(root->right, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        sumHelper(root,sum);
        return sum;
    }