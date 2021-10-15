//3 is very tricky rescursion as well as binary search
3. DFS in BST
The idea is to do binary search in BST.
T.C: O(NH), H is height of BST
S.C: O(H)

    bool findTarget(TreeNode* root, int k) {
        return helper(root, root, k);
    }
    
    bool helper(TreeNode* root, TreeNode* cur, int k){
        if(!cur) return false;
        return search(root, cur, k-cur->val) || helper(root, cur->left, k) || helper(root, cur->right, k);
    }
    
    bool search(TreeNode* root, TreeNode* cur, int k){
        if(!root) return false;
        return (root->val == k) && (root != cur) || 
            
            //If root->val < k, search on right side of the tree.
            (root->val < k) && search(root->right, cur, k) || 
            
            //If root->val > k, search on left side of the tree
            (root->val > k) && search(root->left,cur,k);
    }


1. Using Hashset
T.C: O(N)
S.C: O(N)

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root,s,k);
    }
    
    bool helper(TreeNode* root, unordered_set<int>& s, int k){
        if(!root)return false;
        if(s.count(k-root->val)) return true;
        s.insert(root->val);
        return helper(root->left,s,k) || helper(root->right,s,k);
    }
2. Using 2 pointers
T.C: O(N)
S.C: O(N)

bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(root,res);
        for(int i=0,j=res.size()-1; i<j;){
            if(res[i] + res[j] == k) return true;
            if(res[i] + res[j] < k) i++;
            else j--;
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& res){
        if(!root)return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
