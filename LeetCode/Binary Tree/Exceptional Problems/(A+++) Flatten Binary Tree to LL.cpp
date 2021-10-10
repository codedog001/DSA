// Pre-requisite: In order to understand this, you need to be good at understanding how recursion works
// The top voted recursive solution must be having some hypothesis which I wasn't able to understand, so I made a recursive solution where hypothesis was very clear to me, all that was left was induction and a base case.

// Hypothesis: The function will return head of flattened linked list. If you know recursion, you must be knowing, you don't ask how or why from hypothesis, so it is very straight forward.
// E.g: If I call helper(root->left) it will give me head of left linked list.

// Base Case: if(!root) return NULL;

// Induction: If I have head of both left and right linked list, just a few steps needed to be performed.

// We need to traverse to last node of left linked list and connect it to the head of right.
// Make left of right head, left head and the root -> NULL.
// That's it.
// Now, just write above 3 in order.
// Code:

TreeNode* helper(TreeNode* root){
		//Base Case
        if(!root) return NULL;
        
		//Hypothesis: l and r are heads of flattened left and right linked list.
         TreeNode *l = helper(root->left);
         TreeNode *r = helper(root->right);
        
		//Induction
        if(l && r){
			//Connect last node of left linked list to head of right linked list.
            TreeNode *temp = l;
            while(temp->right) temp = temp->right;
            temp -> right = r;

            l->left = NULL;
            r->left = NULL;
            root->right = l;
            root->left = NULL;
        }
        else if(!r && l){
            root->right = l;
            root->left = NULL;
        }
        
		//Done
        return root;
        
    }
    void flatten(TreeNode* root) {
        helper(root);
        return;
    }