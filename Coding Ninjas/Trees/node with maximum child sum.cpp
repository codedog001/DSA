int sumNode(TreeNode<int>* root){
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++){
        sum+=root->children[i]->data;
    }
    return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    
    if(root== NULL ) return 0;
    TreeNode<int> * result = root;
    int sumOfRoot = sumNode(root);
    int maxSum = sumOfRoot;
    for(int i=0; i<root->children.size(); i++){
        //Hypothesis -> My function will bring the node which has maximum sum.
        TreeNode<int> *temp = maxSumNode(root->children[i]);
        int sumOfChildren = sumNode(temp);
        
        //Compare sum of root vs children. -> Induction
        if(sumOfChildren > sumOfRoot){
            maxSum = sumOfChildren;
            result = temp;
        }
    }
    return result;
}