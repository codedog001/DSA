int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(!root) return 0;
    int left = getSum(root->left);
    int right = getSum(root->right);
    return root->data+left+right;
}