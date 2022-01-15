class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        auto p = node->next;
        node->next = node->next->next;
        delete p;
    }
};