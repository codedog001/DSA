void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root) return;
    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}