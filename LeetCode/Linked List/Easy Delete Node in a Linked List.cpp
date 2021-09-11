void deleteNode(ListNode* node) {
        ListNode * next = node->next;
        node->val = next -> val;
        node ->next = node -> next -> next;
    }