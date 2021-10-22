bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(!root) return false;
    if(root->data == k) return true;
    if(root->data > k) {
        if(searchInBST(root->left, k)) return true;
    }
    if(root->data < k){
        if(searchInBST(root->right, k)) return true;
    }
    return false;
    
}