//3 Step solution - Clean code

ListNode * findMiddle(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode * reverse(ListNode* head){
        ListNode * c= head, * p = NULL, * n = head -> next;
        while(c->next != NULL){
            c->next = p;
            p = c;
            c = n;
            n = c->next;
        }
        c->next = p;
        return c;
        
    }
    void reorderList(ListNode* head) {
        if(!head || !(head->next)) return;
        
        //For E.g: 1->2->3->4->5
        
        //1. Find middle of LL -> 3
        ListNode * mid = findMiddle(head);
        
        //2. Reverse LL from mid->next // 1->2->3->5->4
        ListNode* head2 = reverse(mid->next);
        mid->next = NULL;
        
        //3. Create output LL //1->5->2->4->3
        ListNode *c = head, *rev = head2;
        
        while(c && rev){
            ListNode *n = c->next;
            ListNode *r = rev->next;
            
            c->next = rev;
            rev->next = n;
            
            c=n;
            rev = r;
        }
        
    }