void inOrder(BinaryTreeNode<int>* root){
    if(!root) return;
    inOrder(root->left);
    cout << root -> data << " ";
    inOrder(root->right);
}