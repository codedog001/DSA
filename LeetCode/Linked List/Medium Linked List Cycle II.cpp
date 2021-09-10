    //Reference: https://www.youtube.com/watch?v=QfbOhn0WZ88
    
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next)){
            return NULL;
        }
        ListNode* f=head;
        ListNode* s=head;
        ListNode* entry=head;
        
//         Fast moving by 2 nodes at each time and slow moving by 1 is an optimal rate for travelling minimum distance and reaching the meeting point of the cycle. BUT
//         Even if the rate is not 2:1 it will meet at some point, but will take more no of traversals to do the same.
        
        while(f->next && f->next->next){
            f=f->next->next;
            s=s->next;
            if(f==s){
                
                //the distance between the head location and entry location is
// equal to the sum of 1) the distance between the meeting location and the entry location along the
// direction of forward movement; 2) and a multiple of length of C."
                
                while(s!=entry){
                    s=s->next;
                    entry=entry->next;
                }
                return entry;
            }
        }
        
        return NULL;
    }