// LOGIC:
// We can use two iterations to do that. In the first iteration, 
//we will reset the pointer of one linkedlist to the head of another linkedlist 
//after it reaches the tail node. In the second iteration, we will move two pointers 
// until they points to the same node. Our operations in first iteration will 
// help us counteract the difference. So if two linkedlist intersects, 
// the meeting point in second iteration must be the intersection point. 
// If the two linked lists have no intersection at all, then the meeting pointer 
// in second iteration must be the tail node of both lists, which is null.

// Code:

ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
        if(ha == hb){
            return ha;
        }
        ListNode *d1 = ha, *d2 = hb;
        while(d1 != d2){
            d1 = d1 == NULL ? hb : d1->next;
            d2 = d2 == NULL ? ha : d2->next;
        }
        return !d1 ? NULL : d1;
    }