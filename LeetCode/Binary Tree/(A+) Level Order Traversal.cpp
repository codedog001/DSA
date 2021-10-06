vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        if(!root) return res;
		
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL); //Add a delimiter after first node.
		
        while(pendingNodes.size()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
			
            if(front){
                temp.push_back(front->val);
                if(front->left) pendingNodes.push(front->left);
                if(front->right) pendingNodes.push(front->right);
				
            }else {
			//When a null is encountered temp is cleared and again a null is pushed into the queue, signifying end of this level.
                res.push_back(temp);
                temp.clear();
                if(pendingNodes.size()) pendingNodes.push(NULL);
            }
        }
        return res;
    }
