1. Recursive:

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(val < root->val) root->left = insertIntoBST(root->left, val);
        if(val > root->val) root-> right = insertIntoBST(root->right, val);
        return root;
    }
2. Iterative:

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto node = new TreeNode(val);
        
        if(!root) return node;
        auto cur = root;
        
        while(cur){
            if(cur->val > val){
                if(cur->left) cur = cur -> left;
                else {
                    cur->left = node;
                    break;
                }
            }
            else if(cur->val < val){
                if(cur->right) cur = cur -> right;
                else{
                    cur->right = node;
                    break;
                }
            }
        }
        return root;
    }