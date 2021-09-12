    ListNode* reverse(ListNode * head){
        if(!head || !(head->next)){
            return head;
        }
        ListNode *p = NULL, *c=head, *n=head->next;
        while(c && n && c->next){
            c->next = p;
            p=c;
            c=n;
            n=c->next;
        }
        c->next = p;
        return c;
        
    }
    bool isPalindrome(ListNode* head) {
        if(!(head->next)){
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow -> next;
        }
        
        slow = reverse(slow);
        fast = head;
        while(slow && slow->next){
            if(fast->val != slow->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }