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
    ListNode* partition(ListNode* head, int x) {
        if(!(head) || !(head->next)){
            return head;
        }
        //p1 LL will contain values < x
        //p2 LL will contain values >= x
        
        ListNode * p1 = new ListNode(0);
        ListNode * p2 = new ListNode(0);
        
        
        ListNode *head1 = p1, *head2 = p2;
        
        while(head){
            if(head->val<x){
                p1 -> next=head;
                p1 = p1 -> next;
            }else{
                p2->next = head;
                p2 = p2 -> next;
            }
            head = head->next;
        }
        
        //p2->next contains some value, it should be terminated, otherwise it will become an endless cycle, resulting in TLE.
        
        p2 -> next = NULL;
        
        //Connect list p1 and p2.
        p1 -> next = head2->next;
        return head1->next;
    }
};