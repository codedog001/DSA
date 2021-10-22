#include<climits>
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(!root) return NULL;
    // Write your code here
    int res = INT_MAX;
    int rootData = root->data;
    TreeNode<int> * resNode = NULL;
    if(root->data - x > 0){
        res = rootData;
        resNode = root;
    } 
    
    
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int> * tempNode = getNextLargerElement(root->children[i], x);
        if(!tempNode) return NULL;
        int tempData = tempNode->data;
        if(tempData - x >0 && tempData < res){
            res = tempData;
            resNode = tempNode;
        }
    }
    return res==INT_MAX ? NULL : resNode;
}