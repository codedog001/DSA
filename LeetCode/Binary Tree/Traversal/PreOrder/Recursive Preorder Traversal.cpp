1. Return Vector

vector<int> v;
vector<int> preOrder(TreeNode* root){
    if(!root) return v;
    v.push_back(root->val);
    postOrder(root->left);
    postOrder(root->right); 
    return v;
}

2. Print Value

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root) return;
    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}