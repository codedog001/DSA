ListNode* rece(ListNode* head, int val){
        if(head == NULL) return NULL;
        ListNode* temp = head;
        ListNode * recHead = rece(head->next, val);
        if(temp -> val == val) head = recHead;
        else temp->next = recHead;
        return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode* rec = rece(head, val);
        return rec;
    }