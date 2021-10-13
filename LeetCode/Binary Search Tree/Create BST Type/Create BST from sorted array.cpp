//Using Binary Search
BinaryTreeNode<int>* helper(int* a, int si, int ei){
    if(si>ei) return NULL;
    int mid = (si+ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]);
    root->left = helper(a,si,mid-1);
    root->right = helper(a,mid+1,ei);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(n<=0) return NULL;
    return helper(input,0,n-1);
}