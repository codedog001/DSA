1. Iterative

Node* connect(Node* root) {
	if(!root) return root;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		auto front = q.front();
		q.pop();
		if(!front) {
			if(q.size() > 0) q.push(NULL);
		}
		else{
			front -> next = q.front();
			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
	}
	return root;
}

2. Recursive
Hypothesis: Recursive function will connect the current node with what we tell in con variable.
Root will be connected with NULL.
Root-> left will be connected with Root->right
Root-> right will be connected toroot->next -> left, if root->next -> left doesn't exist then it will be connected to NULL.

Node* connect(Node* root) {
        if(!root) return root;
        helper(root,NULL);
        return root;
    }
    
    void helper(Node* root, Node* con){
        if(!root) return;
        root-> next = con;
        helper(root->left, root->right);
        helper(root->right, root->next ? root->next->left : NULL);
    }
