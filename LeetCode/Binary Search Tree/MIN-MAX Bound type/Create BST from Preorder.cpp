TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        TreeNode * root = helper(preorder, i,INT_MAX);
        return root;
    }
    TreeNode* helper(vector<int>& a, int& i, int bound){
        if(i==a.size() || a[i]>bound) return NULL;
        TreeNode* root = new TreeNode(a[i]);
        i++;
        root->left = helper(a, i, root->val);
        root->right = helper(a, i, bound);
        return root;
    }