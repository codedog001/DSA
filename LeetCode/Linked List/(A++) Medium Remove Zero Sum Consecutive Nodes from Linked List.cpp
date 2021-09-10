//Approach - Prefix Sum
    //Reference - https://www.youtube.com/watch?v=tss5biw6ctI
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        //Experiment to show unordered map is storing most recent key in case of duplicate key
        
        // unordered_map<char, int> x;
        // string s= "abbbcb";
        // int c=1;
        // for(auto &g:s){
        //     x[g] = c;
        //     cout << "PAIR: " << g << " & " <<c << endl;
        //     c++;
        // }
        // for(auto &g:s){
        //     cout << "MAP HAS: " << g << " VAL: " << x[g] << endl;
        // }
        // cout << "RESULT: " << x['b'] << endl;
        
        
        //Create a dummy node in case if final answer is NULL
        ListNode * dummy = new ListNode(0), *temp = head;
        dummy -> next = head;
        
        unordered_map<int, ListNode*> um;
        
        int preSum = 0;
        ListNode * prev = dummy;
        
        while(prev){
            preSum += prev -> val;
            um[preSum] = prev;
            cout << "Making Pair - Presum: " << preSum << " element " << um[preSum]->val << endl;
            prev = prev ->next;
        }
        prev = dummy;
        int tempo = 0;
        
        //Go through the linked list map all nodes with presum value.
        while(prev){
            tempo += prev->val;
            cout << "Pair - Presum " << tempo << " mapped element " << um[tempo]->val << endl;
            prev = prev -> next;
        }
        prev = dummy;
        preSum = 0;
        while(prev){
            //Find most recent nodes having this preSum value
            preSum += prev-> val;
            ListNode* dup = um[preSum]->next;
            
            //Connect the next node of dup having preSum to next of current.
            prev->next = dup;
            prev = prev->next;
        }
  
        return dummy->next;
        
    }    