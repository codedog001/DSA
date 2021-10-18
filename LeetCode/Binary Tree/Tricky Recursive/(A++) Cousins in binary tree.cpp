1. Recursive: Doing DFS. Self-explanatory.

bool isCousins(TreeNode* root, int x, int y) {
        helper(root, x, y, 0, root);
        return depthX == depthY && parentX != parentY;
    }
    
    void helper(TreeNode* root, int x, int y, int depth, TreeNode* par){
        if(!root) return;
        
        if(root-> val == x) {
            depthX = depth;
            parentX = par;
            if(depthY!=-1) return;
        }
        else if(root->val == y){
            depthY = depth;
            parentY = par;
            if(depthX != -1) return;
        }
        
        helper(root->left, x, y, depth+1, root);
        helper(root->right, x, y, depth+1, root);
        
    }
    private:
    int depthX=-1, depthY=-1;
    TreeNode *parentX = NULL, *parentY= NULL;
2. Iterative:
Logic: Doing BFS, If we find one of the nodes having value x or y, say we found x, we make the other one i.e. y = toSearch, when we find both x and y, we have to check whether they are siblings, if they are not siblings, return true, else false.

Note: Code is long, because it is very easy to understand, I'm not a fan of cryptic code.

bool isCousins(TreeNode* root, int x, int y) {
     if(!root || root-> val == x || root -> val == y) return false;
     queue<TreeNode*> q;
     
     int toSearch = -1;
     q.push(root);
     while(!q.empty()){
         int n=q.size();
         vector<TreeNode*> v;
         
         for(int i=0; i<n; i++){
             auto front = q.front();
             q.pop();
             TreeNode* l = NULL, *r=NULL; 
             
             if(front->left) {
                 l=front->left;
                 q.push(l);
                 if(!v.empty()){
                     if(l-> val == toSearch && !sibling(front,l,v[0])) return true;
                 }else{
                     if(l->val == x) {
                     v.push_back(l);
                     toSearch = y;
                     }
                     else if(l->val == y){
                         v.push_back(l);
                         toSearch = x;
                     } 
                 }
             }
             if(front -> right) {
                 r =  front -> right;
                 q.push(r);
                 if(!v.empty()){
                     if(r-> val == toSearch && !sibling(front,v[0],r)) return true;
                 }else{
                     if(r->val == x) {
                     v.push_back(r);
                     toSearch = y;
                     }
                     else if(r->val == y){
                         v.push_back(r);
                         toSearch = x;
                     } 
                 }
             }
         }
 		//If v.size() == 1, it implies, we traversed one level completely and only one of x or y was found, so they don't exist in same level, hence return false.
         if(v.size()==1) return false;
     }
     return false;
 }
 
 bool sibling(TreeNode* root, TreeNode* l, TreeNode* r){
     if((root->left == l && root->right == r) || (root->right==l && root->left == r)) return true;
     return false;
 }