// 0. Iterative Solution:

ListNode* reverseHelper(ListNode* head){
        ListNode* p = NULL, *n = head->next, *c = head;
        while(c){
            c -> next = p;
            p = c;
            c = n;
            if(n) n = n -> next;
        }
        return p;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        return reverseHelper(head);
    }

// 1. Simple recursive solution:

class Solution {
public:
    ListNode* reverseHelper(ListNode* head){
        if(!head) return head;
        if(!(head->next)) return head;
        auto newHead = reverseHelper(head->next);
        
        //Now, linked list looks like: 5->4->3->2<-1;
        //where newHead->data = 5
        
        head -> next -> next = head; // 2->1
        head -> next = NULL; // 1->NULL
        
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return reverseHelper(head);
    }
};

// 2. Slightly different recursive solution: Returns tail along with head of reversed linked list.

pair<ListNode*, ListNode*> reverseHelper(ListNode* head){
        if(!head) return {NULL, NULL};
        if(!(head->next)) return {head, head};
        
        auto oldHead = head;
        auto res = reverseHelper(head->next);
        
        auto newHead = res.first;
        res.second -> next = oldHead;
        oldHead -> next = NULL;
        
        return {newHead, oldHead};
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return reverseHelper(head).first;
    }