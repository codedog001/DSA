3 Steps to get desired result:

Store inorder traversal in vector
Store suffix sum in vector
Final inorder traversal to replace values with values in array
T.C: O(N)
S.C: O(N)

TreeNode* bstToGst(TreeNode *root) {
	if(!root) return root;
    vector<int> a;

//Store inorder traversal in vector - O(N)
    inorder(root, a);
    
//Store suffix sum in vector - O(N)
    for(int i =a.size()-2; i>=0; i--){
        a[i] = a[i] + a[i+1];
    }
	
//Do a final inorder traversal to replace values with values in array - O(N)
    iterativeInorder(root, a);
	return root;
}

void inorder(TreeNode* node, vector<int>& res){
    stack<TreeNode*> s;
    
    while(node || !s.empty()){
        while(node){
            s.push(node);
            node = node->left;
        }
        node = s.top();
        s.pop();
        res.push_back(node->val);
        node =  node->right;
    }
    return;
}

void iterativeInorder(TreeNode* root, vector<int> res){
    stack<TreeNode*> s;
    auto node = root;
    
    int i = 0;
    while(node || !s.empty()){
        while(node){
            s.push(node);
            node = node->left;
        }
        node = s.top();
        s.pop();
        node->val = res[i];
        i++;
        node =  node->right;
    }
    return;
}