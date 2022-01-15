class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head, q = head;
        for(int i=0; i<n; i++) p = p-> next;
        
        //If p is null, head is to be removed.
        if(!p){
            auto newHead = head -> next;
			delete head;
            return newHead;
        }
        
        while(p->next){
            p = p-> next;
            q = q-> next;
        }
        
        //After the end of while loop q will point on previous node of target (to be deleted) node
        auto nodeToRemove = q->next;
        if(nodeToRemove -> next) {
            q -> next = nodeToRemove -> next;
            delete nodeToRemove;
        }
        else q -> next = NULL;
        
        return head;
    }
};