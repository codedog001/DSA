//1. O(1) Space solution
//Very good use of for loop in LL.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        auto p = head;
        
        //1. Insert duplicate nodes adjacent to original LL.
        //Original: 1->2->3
        //Make it: 1->1->2->2->3->3
        
        for(auto l1 = head; l1; l1 = l1->next->next){
            auto newNode = new Node(l1->val);
            newNode->next = l1->next;
            l1-> next = newNode;
        }
        
        //2. Assign random pointer to clone LL
        auto newHead = head->next;
        for (auto l1 = head; l1; l1 = l1->next->next) {
            if (l1->random != NULL) l1->next->random = l1->random->next;
        }
        
        //3. Extract Clone LL from original LL
        for(auto l1 = head; l1; l1 = l1->next){
            auto l2 = l1 -> next;
            l1-> next =  l1-> next-> next;
            if(l2-> next) l2-> next= l2-> next -> next;
        }
        return newHead;
    }
};