BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return NULL;
    if(!root->left && !root->right) return NULL;
    
    root -> left = removeLeafNodes(root->left);
    root -> right = removeLeafNodes(root->right);
    
    return root;
}