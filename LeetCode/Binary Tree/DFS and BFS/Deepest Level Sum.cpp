// Best Explanation behind intuition: https://leetcode.com/problems/deepest-leaves-sum/discuss/1152953/DFS-and-BFS-O(N)-Solutions-or-Short-and-Easy-w-Explanation-or-Beats-100
// 1. DFS:

// Running Sum and deepest should only have  a single copy, therefore they are passed through reference, alternatively they can be taken as global variable, but it is not considered best practice.
int helper(TreeNode* root, int depth, int &deepest, int &sum){
        if(!root) return 0;
        if(!root-> left && !root->right){
            if(depth > deepest) {
                sum = root->val;
                deepest = depth;
            }
            else if(depth == deepest) sum += root->val;
        }
        helper(root->left, depth+1, deepest, sum);
        helper(root->right, depth+1, deepest, sum);
        
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        int deepest = 0;
        int runningSum = 0;
        int sum = helper(root,0,deepest,runningSum);
        return sum;
    }
    
// 2. BFS: Whenever a new level is reached, reset the res to 0, this way res will keep the sum of deepest leaf nodes.

int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        int sum = 0;
        if(!root) return sum;
        
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            sum = 0; //Reset sum after each level.
            for(int i=0; i<n; i++){
                auto front = q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                sum += front->val;
                q.pop();
            }
        }
        return sum;
    }