#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root){
        pair<int,int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    
    //Hypothesis
    pair<int, int> left = getMinAndMax(root->left);
    pair<int, int> right = getMinAndMax(root->right);
    
    
    //Induction
    int minLeft = left.first;
    int minRight = right.first;
    
    int minRes = min(root->data, min(minLeft, minRight));
    
    int maxLeft =  left.second;
    int maxRight = right.second;
    
    int maxRes = max(root->data, max(maxLeft, maxRight));
    
    pair<int, int> res;
    res.first = minRes;
    res.second = maxRes;
    return res; 
}