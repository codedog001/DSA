//Iterative
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        auto dummy = new ListNode();
        auto cur = dummy;        
        int carry = 0;
        
        while(h1 || h2){
            int x = 0, y = 0, sum = 0;
            if(h1) x = h1 -> val;
            if(h2) y = h2 -> val;
            
            sum = x + y + carry;
            int data = sum % 10;
            carry = sum / 10;
            
            auto newNode = new ListNode(data);
            
            cur -> next = newNode;
            cur = cur -> next;
            
            if(h1) h1 = h1->next;
            if(h2) h2 = h2->next;
        }
        
        if(carry > 0){
            auto newNode = new ListNode(carry);
            cur -> next = newNode;
        }
        
        return dummy -> next;
    }
};

// Recursive
class Solution {
public:
    void findSum(ListNode* cur, ListNode* h1, ListNode* h2, int carry){
        int x = 0, y = 0, sum = 0;
        if(!h1 && !h2) {
            if(carry>0){
                auto newNode = new ListNode(carry);
                cur -> next = newNode;
            }
            return;
        }
        if(h1) x = h1 -> val;
        if(h2) y = h2 -> val;
        
        sum = x + y + carry;
        auto newNode = new ListNode(sum%10);
        cur -> next = newNode;
        
        ListNode* p = NULL, *q = NULL;
        if(h1 && h1->next) p = h1->next;
        if(h2 && h2->next) q = h2->next;
        
        findSum(cur->next, p, q, sum/10);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode();
        findSum(dummy, l1, l2, 0);
        return dummy -> next;
    }
};