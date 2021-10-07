1. BFS: It is more efficient than DFS for this problem.

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int mindepth = 0;
        while(!q.empty()){
            mindepth++;
            int k= q.size();
            for(int j=0; j<k;j++){
                auto front = q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
                if(!front->left && !front->right) return mindepth; 
            }
        }
        return -1;
    }
    
2. DFS

int minDepth(TreeNode* root) {
	if(!root) return 0;
	int left = minDepth(root->left);
	int right = minDepth(root->right);

	if(left==0 || right == 0) return max(left,right) + 1;
	else return 1+min(left,right);
}