ListNode* insertionSortList(ListNode* head) {
        if(!head || !(head -> next)){
            return head;
        }
        //Inserting nodes of unsorted LL into a seperate sorted LL.
        ListNode * pre = new ListNode(0), * sortedHead = pre, * cur = head;
        
        while(cur){
            ListNode *n = cur -> next;
            while(pre && pre->next && pre->next->val < cur->val){
                pre = pre-> next;
            }
            //Insert cur node of unsorted LL into sorted LL
            cur->next = pre->next;
            
            pre->next = cur;
            
            //Move to next position in unsorted LL
            cur = n;
            
            //Bringing pre back to head of sorted LL.
            pre = sortedHead;
        }
        
        return sortedHead -> next;
    }