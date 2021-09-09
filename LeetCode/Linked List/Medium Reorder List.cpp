// The idea is to create deep copy of given LL and reverse it. Now we have to pick one element from given LL and next element from reversed LL. Terminate the list at right place. That's it.

// Given LL: 1->2->3->4->5
// Reversed: 5->4->3->2->1
// Output: 1->5->2->4->3

// Start from head of given LL and terminate it at index 2 (The termination depends on length of LL)

ListNode *reverse(ListNode *head) {
    if(head == NULL || head -> next == NULL) return head;
    ListNode * prev = NULL, * curr = head, * n = curr->next;
    while(curr->next!=NULL){
        curr->next = prev;
        prev = curr;
        curr = n;
        n = n->next;
    }
    curr->next = prev;
    return curr;
}
    void reorderList(ListNode* head) {
         
        ListNode *c = head;
        ListNode *rL = new ListNode(0);
        ListNode *m = rL;
        int len = 0;
        
        //1. Create Deep copy of given LL
        while(c){
            ListNode *h = new ListNode(c->val);
            m->next = h;
            m=m->next;
            c=c->next;
            len++;
        }
        m->next = NULL;
        
        //2. Reverse the duplicate LL
        ListNode *rH = reverse(rL->next);
        
        ListNode* r= rH;
        c=head;
        ListNode* n= head->next;
        ListNode* rn = rH->next;
        int temp =len;

        //3. Starting from head of given LL, take every other element from reversed LL.
        while(c && c->next && r &&  r->next && temp>(len/2)+1){
            n=c->next;
            rn=r->next;  
            c->next = r;
            r->next = n;
            c=n;
            r=rn;
            temp--;
        }
        
        //4. Terminate LL at right location depending on its length.
        if(len%2!=0){
            c->next  = NULL;
        }else{
            c->next->next = NULL;
        }
    }