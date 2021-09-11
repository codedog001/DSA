int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> setG (nums.begin(), nums.end());
        int res = 0;
        while (head != NULL) {
            if (setG.count(head->val) && (head->next == NULL || !setG.count(head->next->val))) res++;
            head = head->next;
        }
        return res;
    }