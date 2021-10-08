RECURSIVE SOLUTION IS BETTER

1. Recursive Reverse Preorder Traversal:
Preorder: Left->root->Right
Reverse Preorder: Right->root->left
First we will store all the right side nodes, and for the left we will be only storing the value which are at a new depth.

T.C: O(N)
S.C: O(H), where H is height of binary tree, it is better than iterative solution

void helper(TreeNode* root, int depth, vector<int> &res){
	if(!root) return;
	//Check whether we are currently at a new depth in the tree.
	if(depth==res.size()) res.push_back(root->val);
	
	helper(root->right, depth+1, res);
	helper(root->left, depth+1, res);
}

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	int depth = 0;
	helper(root, depth, res);
	return res;
}


2. BFS Logic: Travel the tree level wise and insert the value of last node of current level to result.
In this case:
T.C: O(N)
S.C: will be high, as the queue will store all the nodes present at a level, therefore a recursive solution is better.

// BFS
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
			
			// This is the only additional step to the BFS to get answer.
            res.push_back(q.back()->val);
			
            for(int i=0; i<n; i++){
                auto front= q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
            }
        }
        return res;
    }