ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * p = dummy, *c = head, *temp=NULL;
        int m= n;
        
        while(c && m!=1){
            c=c->next;
            m--;
        }
        temp = head;
        
        //Now temp stands on node which is to be deleted
        while(c->next){
            c=c->next;
            temp=temp->next;
            p=p->next;
        }
        
        ListNode * nex = NULL;
        
        if(temp->next) nex= temp -> next;
        else nex = NULL;
        
        p->next = nex;
        return dummy->next;
    }