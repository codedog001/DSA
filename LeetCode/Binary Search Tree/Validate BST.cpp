1. Iterative Solution
Just add 1 step to iterative inorder traversal

bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode * node = root, *prev = NULL;
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node -> left; 
            }
            node = s.top();
            s.pop();
			
			//This is the additional step.
            if(prev && node->val <= prev->val) return false;
            prev = node;
            node = node->right;
        }
        return true;
    }
    
2. Recursive Solution

bool helper(TreeNode* root, long minVal, long maxVal){
     if(!root) return true;
     if(root->val >= maxVal || root->val <= minVal) return false;
     
     //1. For root->left i.e. left subtree, the minimum could be any low value, but the maximum is restricted to be less than root->val.
     //2. For root->right i.e. right subtree, the maximum could be any high value, but the minimum is restricted to be more than root->val.
     return helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal);
 }
 bool isValidBST(TreeNode* root) {
     return helper(root, LONG_MIN, LONG_MAX);
 }