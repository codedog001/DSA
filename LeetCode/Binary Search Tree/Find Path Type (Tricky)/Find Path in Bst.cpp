Coding Ninjas
P.S: Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {

	// Write your code here
    
    if(!root) return NULL;
    
    if(root->data == data){
        vector<int>* res = new vector<int>();
        res->push_back(root->data);
        return res;
    }
    
    auto left = getPath(root->left, data);
    auto right = getPath(root->right, data);
    if(left){
        left->push_back(root->data);
        return left;
    }
    else if(right){
    	right->push_back(root->data);
        return right;
    }
    else return NULL;
    
}