//1. Using Hashset - O(N) space

ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next)){
            return NULL;;
        }
        unordered_set<ListNode*> m;
        ListNode* temp = head;
        
        while(temp){
            if(m.find(temp) == m.end()){
                m.insert(temp);
            }else{
                return temp;
            }
            temp = temp->next;
        }
        
        return NULL;
    }