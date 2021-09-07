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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        vector<int> monoDec;
        
        //Using MONO Dec. stack - Only Maximum element remains in the stack.
        //Start traversing from last element.
        
        if(head == NULL){
            return res;
        }
        
        ListNode* p = head;
        while(p!=NULL){
            res.push_back(p->val);
            p=p->next;
        }
        
        for(int i=res.size()-1; i>=0; i--){
            int cur = res[i];
            
            //Remove all elements smaller than current element 
            while(!monoDec.empty() && monoDec.back() <= cur){
                monoDec.pop_back();
            }
            
            //If there is no element in stack, then there is no greater element after current element.
            res[i] = monoDec.empty() ? 0 : monoDec.back();
            monoDec.push_back(cur);
        }
        
        
        return res;
    }
};