//If flag isReversed is true, then insert the value in temp in reverse order, and switch the boolean after each level.

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool isReversed = false;
        while(!q.empty()){
            int n= q.size();
            vector<int> temp(n);
            for(int i=0; i<n; i++){
                auto front = q.front();
                q.pop();
				
				//isReversed -> true, then insert elements in temp in reverse fashion.
                int index = isReversed ? n-i-1 : i;
                temp[index] = front->val;
                
                if(front -> left) q.push(front->left);
                if(front -> right) q.push(front->right);
            }
            isReversed = !isReversed;
            res.push_back(temp);
        }
        return res;
    }
