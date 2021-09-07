/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    //USING Reverse LL METHOD
    
    ListNode * reverse(ListNode * head){
       if(head==NULL || head->next == NULL){
           return head;
       }
        ListNode *p = reverse(head->next);
        head -> next -> next = head;
        head -> next = NULL;
        return p;
        
    }
    
    
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode *ra = reverse(a);
        ListNode *rb = reverse(b);
        
        int carry = 0;
        ListNode *rc = new ListNode(0); //A reverse c (sum) LL initialized with a dummy node.
        ListNode *l3 = rc; // A pointer that keeps track of addresses of c node.
        
        while(ra!=NULL || rb!=NULL){
            //If any of them is not null we will continue addition by taking the one with null as 0 value
            int f = (ra!=NULL) ? ra->val : 0;
            int s = (rb!=NULL) ? rb->val : 0;
            
            int currentSum = f + s + carry;
            carry = currentSum/10; // if sum = 12 -> 12/10 = 1
            int finalVal = currentSum % 10; // if sum = 12, final val = 12%10 = 2, while carry = 1.
            
            ListNode *newNode = new ListNode(finalVal);
            l3->next = newNode;
            
            if(ra!=NULL){
                ra = ra->next;
            }
            if(rb!=NULL){
                rb = rb->next;
            }
            l3 = l3->next;
            
        }
        
        //Create new Node if carry == 1
        if(carry>0){
            ListNode *carryNode = new ListNode(carry);
            l3->next = carryNode;
            l3 = l3->next;
        }
        
        ListNode * sum = reverse(rc->next);
        return sum;
        
    }
    
};