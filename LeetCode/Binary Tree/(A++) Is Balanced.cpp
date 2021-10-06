pair<int,bool> helper(TreeNode * root){
if(!root){
	pair<int, bool> p;
	p.first = 0;
	p.second = true;
	return p;
}

pair<int, bool> left = helper(root->left);
pair<int, bool> right = helper(root->right);

int leftHeight = left.first;
int rightHeight = right.first;

pair<int, bool> res;
if(!left.second || !right.second || abs(leftHeight - rightHeight) > 1) res.second = false;
else res.second = true;

int totalHeight = 1+max(leftHeight, rightHeight);
res.first = totalHeight;

return res;
}

bool isBalanced(TreeNode* root) {
	if(!root) return true;
	pair<int, bool> res = helper(root);
	return res.second;
}