#include<queue>
#include<vector>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    vector<Node<int>*> res;
	if(!root) return res;
    pendingNodes.push(root);
    pendingNodes.push(NULL); //Add a delimiter after first node.    	
    Node<int>* dummy = new Node<int>(0);
	Node<int>* tail = dummy;
    
    while(pendingNodes.size()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
			
        if(front){
            Node<int>* n = new Node<int>(front->data);
            if(!(dummy->next)) {
                dummy -> next = n;
                tail = n;
            }else{
                tail->next = n;
                tail=tail->next;
            }
            
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        
        }else{
            tail->next = NULL;
            res.push_back(dummy->next);
            tail = dummy;
            dummy->next = NULL;
            
            if(pendingNodes.size()) pendingNodes.push(NULL);
        }
    }
    return res;
}