bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
	if(root1 -> data == root2 -> data){
        if(root1 -> children.size() == root2->children.size()){
            for(int i=0; i<root1->children.size(); i++){
				if(root1->children[i] -> data != root2->children[i]->data) return false;
            }
            return true;
        }else return false;
    }
    else return false;
    
    for(int i=0; i<root1->children.size(); i++){
        if(areIdentical(root1->children[i], root2->children[i])) return true;
    }
    return false;
}