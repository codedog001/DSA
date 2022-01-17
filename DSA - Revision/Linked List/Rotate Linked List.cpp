int findLen(ListNode* head){
        int i=0;
        for(i=0; head; i++) head = head -> next;
        return i;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next) return head;
        
        int len = findLen(head);
        k = k%len;
        if(k==0) return head;
        
        auto p = head, q = head;
        for(int i=0; i<k; i++) p = p -> next;
        
        while(p->next){
            p = p-> next;
            q = q-> next;
        }
        auto newHead = q->next;
        q->next = NULL;
        p->next = head;
        return newHead;
    }