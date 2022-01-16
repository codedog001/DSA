1. Iterative:

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* n = head, *p = head, *newHead = NULL;
        
        if(k==1) return head;
        auto dummy = new ListNode();
        auto c= dummy;
        dummy -> next = head;
        
        while(n){
            
            //1. Terminate last node of the current batch with NULL.
            for(int i=0; n && i<k-1; i++){
                n = n-> next;
            }
            
            //If n is null, current batch has lesser than k nodes left -> No need to reverse.
            if(!n) break;
            
            p = NULL;
            if(n-> next) {
                p = n-> next;
                n ->next = NULL;
                n = p;
            }else n = NULL;
            
            //2. Reverse Helper returns head and tail of reversed linked list.
            auto reversePair = reverseHelper(c->next);
            
            //3. Now we have head and tail, attach them to previous and next of current linked list
            ListNode* reversedTail = reversePair.second, *reversedHead = reversePair.first;
            if(reversedTail) reversedTail -> next = n;
            
            if(!newHead) newHead = reversedHead;
            c->next = reversedHead;           
            c=reversedTail;
        }
        return newHead;
    }
    
    pair<ListNode*, ListNode*> reverseHelper(ListNode* head){
        if(!head) return {NULL, NULL};
        if(!(head->next)) return {head, head};
        
        auto oldHead = head;
        ListNode* p = NULL, *c = head, *n = head->next;
        
        while(c){
            c->next= p;
            p=c;
            c=n;
            if(n) n=n->next;
        }
        return {p,oldHead};
    }
};
2. Recursive:

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        if(!head) return head;
        
        auto p = head;
        for(int i=0; p && i<k-1; i++) p = p-> next;
        
        if(!p) return head;
        
        ListNode* n = NULL;
        if(p-> next) {
            n = p->next;
            p-> next = NULL;
        }
        
        ListNode* reversedHead = reverseKGroup(n, k);
        
        reverse(head);
        head -> next = reversedHead;
        
        return p;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        
        auto newHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return newHead;
    }
};