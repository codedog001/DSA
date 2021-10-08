1. Return Vector
vector<int> v;
vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return v;
    inorderTraversal(root->left);
    v.push_back(root->val);
    inorderTraversal(root->right);
    return v;
}

2. Print
void inOrder(BinaryTreeNode<int>* root){
    if(!root) return;
    inOrder(root->left);
    cout << root -> data << " ";
    inOrder(root->right);
}