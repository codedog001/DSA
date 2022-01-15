Iterative:

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        auto dummy = new ListNode();
        auto cur = dummy;
        
        while(h1 && h2){
            if(h1->val <= h2->val){
                cur->next = h1;
                h1 = h1->next;
            }else{
                cur->next = h2;
                h2 = h2->next;
            }
			cur = cur->next;
        }
        if(h1) cur -> next = h1;        
        else if(h2) cur -> next = h2;
        
        return dummy -> next;
    }
};
Recursive:

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        
        if(h1 -> val <= h2 -> val){
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        }else{
            h2->next = mergeTwoLists(h2->next, h1);
            return h2;
        }
    }
};