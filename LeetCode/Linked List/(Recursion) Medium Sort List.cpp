// 1. Using 3 pointers

// Maintain 3 pointers: prev, curr and next.
// Traverse the linked list, till n!=NULL.

ListNode* swapPairs(ListNode* head) {
        if(head== NULL || head -> next == NULL){
            return head;
        }
        ListNode *p = NULL, *c=head, *n = head -> next;
        while(n!=NULL){
            ListNode *temp = c->next;
            c->next = n->next;
            n->next = c;
            if(p)
                p->next = temp;
            
            if(!p)
                head = n;
            //Move the pointers to next position
            p=c;
            if(c->next){
                c=c->next;
                n= c->next;
            }else{
                n=NULL;
            }
        }
        return head;
    }
//2. Using Recursion

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head== NULL || head -> next == NULL){
            return head;
        }
        // Eg: 1->2->3->4
        ListNode * temp = head->next; // temp = 2
        head->next = swapPairs(head->next->next);// 1->4->3
        temp->next = head; // 2->1->4->3
        return temp;
    }
};