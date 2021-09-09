ListNode *reverse(ListNode *head) {
    // Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }
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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !(head->next) || left==right){
            return head;
        }
        //1. Point on nodes which are to be reversed.
        
        ListNode *prev = new ListNode(0);
        prev ->next = head;
        
        ListNode *temp = head;
        
        //Mark Left head
        for(int i=1; temp && temp-> next && prev && prev-> next && i<left; i++){
            temp = temp -> next;
            prev = prev -> next;
        }
        
        ListNode * head1 = temp;
        prev -> next = NULL;
        
        
        //Mark Right Head
        right-=left;
        while(temp && right!=0){
            temp = temp -> next;
            right--;
        }
        
        ListNode *n = NULL;
        if(temp->next){
            n= temp -> next;
        }
        
        ListNode * head2 = temp;
        
        head2 -> next = NULL;
        
        ListNode *rh = reverse(head1);

        prev -> next = rh;
        head1->next = n;
      
        if(left!=1){
            return head;
        }else{
            return rh;
        }
        
    }