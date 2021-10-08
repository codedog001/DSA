1. Return Vector

vector<int> v;
vector<int> postOrder(TreeNode* root){
    if(!root) return v;
    postOrder(root->left);
    postOrder(root->right); 
    v.push_back(root->val);
    return v;
}

2. Print Value

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root) return;
    preOrder(root->left);
    preOrder(root->right);
    cout << root-> data << " ";
}