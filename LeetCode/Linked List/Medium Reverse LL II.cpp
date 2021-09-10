//The idea is to insert a node (n here) b/w pre and pre->next, then keep increasing n by 1 position until we reach the difference right - left.

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || !(head->next) || left==right){
        return head;
    }
    ListNode *dummy= new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    
    for(int i=0;i<left-1;i++){ 
        pre=pre->next;
    }
    
    ListNode * start = pre->next;
    ListNode *n = start->next;
    
    for(int i=0; i<right-left; i++){
        
        start->next = n->next;
        
        //Make sure n->next is assigned to pre->next and not start, it will only be assigned to start when loop runs for first time, after that start moves away 1 position.
        n->next = pre->next;
        pre->next = n;
        n= start -> next;
    }
    return dummy->next;
}