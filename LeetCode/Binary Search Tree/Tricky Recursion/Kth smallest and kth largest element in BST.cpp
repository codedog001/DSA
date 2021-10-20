1st poblem: kth smallest element

int kthSmallest(TreeNode* root, int k) {
        pair<int, int> res;
        //Hypothesis :
        //res.first is the kth smallest element and res.second is keeping track of k.
        
        helper(root, k, res);
        return res.first;
    }
    
    void helper(TreeNode *root, int k, pair<int,int>& res){
        if(!root) return;
        helper(root->left, k, res);
        res.second++;
        if(res.second == k) res.first = root->val;
        helper(root->right, k, res);
    }

----------------------------------------------------------------------------------------------------------------------------------

2nd Problem: kth largest element in binary tree- Just change left and right -> DONE.

int kthSmallest(TreeNode* root, int k) {
        pair<int, int> res;
        //Hypothesis :
        //res.first is the kth smallest element and res.second is keeping track of k.
        
        helper(root, k, res);
        return res.first;
    }
    
    void helper(TreeNode *root, int k, pair<int,int>& res){
        if(!root) return;
        helper(root->right, k, res);
        res.second++;
        if(res.second == k) res.first = root->val;
        helper(root->left, k, res);
    }