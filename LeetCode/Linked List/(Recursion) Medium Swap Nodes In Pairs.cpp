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