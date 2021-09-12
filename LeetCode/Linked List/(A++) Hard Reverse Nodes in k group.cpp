1. Recursive - 3 Steps:

Hypothesis
Base Case
Induction
Code:

ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *c = head;
        int count = 0;
        
        //1. Reach kth node if it exists, else return head
        while(count < k){
		//Base Case:
            if(!c) return head;
            c=c->next;
            count++;
        }
        
        //2. Hypothesis - Apply recursion from kth node
        ListNode *recHead = reverseKGroup(c,k);
        
        //3. Induction - Reverse nodes from head to k
        ListNode *pre = recHead;
        
        //Assign c to head again
        c = head;
        
        //Reverse LL as usual
        while(c && count>0){
            ListNode *n = NULL;
            if(c->next) n = c->next;
            c->next = pre;
            pre = c;
            c=n;
            count--;
        }
        return pre;
    }
2. Iterative:

ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        
        ListNode *dummy = new ListNode(0);
        ListNode *c = dummy, *p = dummy, *n = dummy;
        dummy->next = head;
        int len = 0;
        
        //1. Find Length of given LL
        while(c->next){
            c=c->next;
            len++;
        }
        //2. Until length >= k, process of reversing k nodes will continue.
        while(len>=k){
            c = p-> next;
            n = c-> next;
            
            for(int i=1; i<k; i++){
                c->next = n->next;
                n->next = p->next;
                p->next = n;
                n = c->next;
            }
            p= c;
            len -= k;
        }
        return dummy ->next; 
    }