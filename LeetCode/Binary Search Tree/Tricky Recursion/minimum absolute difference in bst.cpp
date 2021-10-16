Logic: In case of BST, inorder traversal is sorted.
Here, mini is the final result, prev is the value of last traversed node.

int helper(TreeNode* root, int& mini, int& prev){
    if(!root) return mini;
    
    helper(root->left, mini, prev);
    
    if(prev != INT_MAX) mini = min(root->val-prev, mini);
    prev = root->val;
    
    helper(root->right, mini, prev);
    return mini;
}

int getMinimumDifference(TreeNode* root) {
    int mini = INT_MAX, prev = INT_MAX;
    helper(root,mini, prev);
    return mini;
}