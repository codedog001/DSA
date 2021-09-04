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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
            if(h1==NULL){
        return h2;
    }else if(h2==NULL){
        return h1;
    }
    ListNode * fh = h1;
    ListNode * ft = h1;
    if(h2->val <= h1->val){
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }else{
        h1 = h1->next;
    }
    while(h1!=NULL && h2!=NULL){
        if(h1->val < h2->val){
            ft->next = h1;
            h1 = h1->next;
        }else{
            ft->next = h2;
            h2 = h2-> next;
            
        }
        ft = ft-> next;
    }
    
    while(h1!=NULL){
        ft->next = h1;
        h1=h1->next;
        ft=ft->next;
    }
    while(h2!=NULL){
        ft->next = h2;
        h2=h2->next;
        ft=ft->next;
    }
    
    return fh;
    }
};