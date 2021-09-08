class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> vec;
    Solution(ListNode* head) {
        while(head){
            vec.push_back(head->val);
            head = head -> next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};