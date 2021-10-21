    node* bd(node* root){
    // Base case.
    if (root == NULL)
        return root;
 
    // Convert the left subtree and link to root
    if (root->left != NULL) {
        node* left = bd(root->left);
 
        while(left->right) left=left->right;
 
        left->right = root;
 
        root->left = left;
    }
 
    if (root->right != NULL) {
        node* right = bd(root->right);
 
        while(right->left) right = right -> left;
 
        right->left = root;
 
        root->right = right;
    }
 
    return root;
}