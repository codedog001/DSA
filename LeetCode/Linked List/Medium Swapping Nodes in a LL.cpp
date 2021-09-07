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


//Clever approach, n2 is marked on head when k=0.
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode * temp = head;
        int m = k;
        
        while(m!=1){
            temp=temp->next;
            m--;
        }
        ListNode *n1 = temp;
        ListNode *n2 = head;
        
        while(temp->next != NULL){
            n2 = n2 -> next;
            temp = temp -> next;
        }
        
        
        swap(n1->val, n2->val);
        return head;
    }
};