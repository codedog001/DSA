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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head-> next== NULL || head->next->next==NULL){
            return head;
        }
        ListNode* e = head->next, * od = head,* ehead = head->next;

        while(e && e->next){
            od->next = od->next->next;
            e->next = e->next->next;   
            e=e->next;
            od=od->next;
        }
        od->next = ehead;
        return head;
    }
};