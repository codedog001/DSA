    //0. Recursive
        Node *flatten(Node *root)
        {
        // Your code here
        if(!root || !root->next ) return root;
        root-> next = flatten(root->next);
        root = mergeTwoLists(root, root->next);
        return root;
        }
        
        Node* mergeTwoLists(Node* h1, Node* h2) {
        auto dummy = new Node(0);
        auto cur = dummy;
        
        while(h1 && h2){
            if(h1->data <= h2->data){
                cur->bottom = h1;
                h1 = h1->bottom;
            }else{
                cur->bottom = h2;
                h2 = h2->bottom;
            }
			cur = cur->bottom;
        }
        if(h1) cur -> bottom = h1;        
        else if(h2) cur -> bottom = h2;
        
        return dummy -> bottom;
    }

    


//1. Iterative
    
    
    `Node* mergeTwoLists(Node* h1, Node* h2) {
        auto dummy = new Node(0);
        auto cur = dummy;
        
        while(h1 && h2){
            if(h1->data <= h2->data){
                cur->bottom = h1;
                h1 = h1->bottom;
            }else{
                cur->bottom = h2;
                h2 = h2->bottom;
            }
			cur = cur->bottom;
        }
        if(h1) cur -> bottom = h1;        
        else if(h2) cur -> bottom = h2;
        
        return dummy -> bottom;
    }

    
    Node *flatten(Node *root)
    {
    // Your code here
    if(!root || !root->next ) return root;
    auto h1 = root, h2 = root->next;
    
    while(h2){
        auto n = h2? h2->next : NULL;
        auto merged = mergeTwoLists(h1, h2);
        h1 = merged;
        h2=n;
    }
    return h1;
    }