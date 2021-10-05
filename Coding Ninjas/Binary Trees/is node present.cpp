bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root){
    if(root->data == x) return true;
    if(isNodePresent(root->left,x)) return true;
    if(isNodePresent(root->right,x)) return true;
    
    return false;
    }
}