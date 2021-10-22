void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return;
    
    if(!root->left && root->right) cout << root->right -> data << " ";
    if(!root->right && root->left) cout << root -> left -> data << " ";
    
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}