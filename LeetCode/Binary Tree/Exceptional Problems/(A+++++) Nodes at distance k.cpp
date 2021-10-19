A++++++ Greatest Binary Tree Problem

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        
        //1. Store parent nodes of all nodes.
        unordered_map<TreeNode*, TreeNode*> parent;
        storeParent(root, parent);
        
        //2. Move outward from target node by 1 distance at a time until k is reached
        unordered_map<TreeNode*, bool> seen;
        queue<TreeNode*> q;
        
        //Note that we are pushing target in the queue, not the root node, because we have to move outward from the target node, and not the root node.
        q.push(target);
        seen[target] = true;
        int curLevel = 0;
        
        //After completion of below while loop, queue will have the nodes at distance = k from target node
        while(!q.empty()){
            int n= q.size();
            if(curLevel++ == k) break;
            // curLevel++;
            for(int i=0; i<n; i++){
                auto node = q.front();
                q.pop();
                
                //Travel to the left if not already visited (by 1 distance)
                if(node -> left && !seen[node->left]){
                    q.push(node->left);
                    seen[node->left] = true;
                }
                //Travel to the right if not already visited (by 1 distance)
                if(node-> right && !seen[node->right]){
                    q.push(node->right);
                    seen[node->right] = true;
                }
                
                //Travel parent node if not already visited (by 1 distance)
                if(parent[node] && !seen[parent[node]]){
                    q.push(parent[node]);
                    seen[parent[node]] = true;
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
void storeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
                
                //Map left child with parent
                m[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                
                //Map right child with parent
                m[front->right] = front;
            }
        }
    }
