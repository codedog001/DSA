1. Reversing half of linked list:

class Solution {
public:
  ListNode* findMid(ListNode* head){
        auto s = head, f = head;
        while(f && f -> next){
            s = s-> next;
            f = f-> next -> next;
        }
        return s;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        
        auto newHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        auto mid = findMid(head);
        
        auto reverseHead = reverse(mid);
                
        while(reverseHead){
            if(head -> val == reverseHead -> val){
                head = head -> next;
                reverseHead = reverseHead-> next;
            }
            else return false;
        }
        return true;
    }
};


2. Using stack:

class Solution {
public:
    
    int findLen(ListNode* head){
        int i =0;
        for(i=0; head; i++) head = head -> next;
        return i;
    }
    
    ListNode* findMid(ListNode* head){
        auto s = head, f = head;
        while(f && f -> next){
            s = s-> next;
            f = f-> next -> next;
        }
        
        return s;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        int size = findLen(head);
        auto s = findMid(head);
        stack<int> st;
        auto p = head;
        while(p != s){
            st.push(p->val);
            p = p->next;
        }
        if(size%2 != 0) s= s->next;
        
        while(s){
            if(s->val == st.top()){
                st.pop();
                s = s-> next;
            }
            else return false;
        }
        return true;
    }
};