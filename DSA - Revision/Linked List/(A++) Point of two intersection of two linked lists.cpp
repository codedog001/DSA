class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto d1 = headA, d2 = headB;
        while(d1 != d2){
            if(d1) d1 = d1 -> next;
            else d1 = headB;
            if(d2) d2 = d2 -> next;
            else d2 = headA;
        }
        
        return d1;
    }
};