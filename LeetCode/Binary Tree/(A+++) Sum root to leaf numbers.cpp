1. Recursive Solution
T.C: O(n)
S.C: O(H), where H is height of tree.

class Solution {
    void sumNum(TreeNode* root, int t, int& res){
        if(!root) return;
        t = t*10 + root->val;
        if(!root->left && !root-> right) {
            res+= t;
            return;
        }
        sumNum(root->left, t, res);
        sumNum(root->right, t, res);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        sumNum(root, 0, res);
        return res;
    }
};
2. Iterative Solution - Preorder Traversal of tree.
T.C: O(n)
S.C: O(n)

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int t = 0, res = 0;
        stack<pair<TreeNode*, int>> s;
        auto node = root;
        s.push({node,0});
        while(!s.empty()){
            node = s.top().first;
            t = s.top().second;
            s.pop();
            if(node){
                t = t*10 + node->val;
                if(!node->left && !node->right) res+=t;
                else{
                    if(node->right) s.push({node->right, t});
                    if(node->left) s.push({node->left, t});
                }
            }
        }
        return res;
    }
};