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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> res;

        while(temp!=NULL){
            res.push_back(temp->val);
            temp = temp -> next;
        }
        // int i = 0;
        // int j = res.size()-1;
        for(int i=0, j = res.size()-1; i<=res.size()/2; i++,j--){
            if(res[i]!=res[j]){
                return false;
            }
        }
        return true;
     
    }
};