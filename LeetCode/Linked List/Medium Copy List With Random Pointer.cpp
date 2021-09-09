// Reference: https://www.youtube.com/watch?v=VNf6VynfpdM

// 1. Using Hashmap

// Node* copyRandomList(Node* head) {
// map<Node*, Node*> m;
// Node* c = head;

//1. Map the nodes of new LL to original LL

while(c){
	//Key: Original Address - Value: New Address of copied node
	m[c] = new Node(c->val);
	c = c-> next;
}

c = head;

//2. Assign next and random of original LL to new LL

while(c){
	m[c]->next = m[c->next];
	m[c]->random = m[c->random];
	c= c->next;
}
return m[head];
}
// 2. By Creating Adjacent Duplicate Nodes

Node* copyRandomList(Node* head) {
        //Using O(1) extra space.
        
        if(!head){
            return head;
        }
        //1. Create duplicate nodes adjacent to original ones. (This helps to know random of original nodes easily.)
        //Output of step 1: 1->1'->2->2'->3->3'->NULL
        Node * c = head;
        while(c){
            Node * n = c->next;
            c->next = new Node(c->val);
            c->next->next = n;
            c=n;
        }
        
        c= head;
        
        //2. Create Random pointer for duplicate nodes.
        
        while(c){
            if(c->random!=NULL){
                c->next->random = c->random->next;                
            }
            c = c-> next->next;
        }
        
        //3. Seperate Duplicate LL from original one.
        c = head;
        Node* cH = c->next;
        Node* copy = cH;
        
        while(copy -> next){
            //Get Original LL
            c->next = c->next->next;
            c = c-> next;
            
            //Get Duplicate LL
            copy -> next = copy->next->next;
            copy = copy ->next;
        }
        c->next = c->next->next;
        
        return cH;
    }

	
