//The merge process
	ListNode* merge(ListNode *l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode * dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        while(l1 && l2){
            if(l1-> val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp -> next = l2;
                l2 = l2->next;
            }
            temp = temp -> next;
        }
        if(!l1) temp->next = l2;
        if(!l2) temp->next = l1;
        
        return dummy -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        int len = lists.size();
		
		//Merge 2 lists until len reaches 1. Avoid using push_back() and pop_back(), it is adding to the time complexity, this is a workaround loop to avoid that.
        while (len > 1) {
            for (int i = 0; i < len / 2; i++) {
                lists[i] = merge(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        return lists[0];
    }