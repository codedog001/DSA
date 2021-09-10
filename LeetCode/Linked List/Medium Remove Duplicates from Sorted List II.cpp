// 1. Using 3 pointers - O(1) Space
// Code:

//Logic: c will be standing on last duplicate element of a particular val, if c->next == p, the val was unique and p can be moved further, else p will directly link to n.

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *c = head, *n = c->next;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        p->next = head;
        
        while(c && n){
            int val = c->val;
            while(c && c->next && val == c->next->val){
                c=c->next;
            }
            if(p->next == c){
                p=p->next;
            }
            if(c->next) n=c->next;
            else n= NULL;
            p->next = n;
            c=n;
        }
        return dummy->next;
    }
// 2. Using Multimap - O(N) space

//i. Traverse all nodes and put them in multimap.
//ii. Remove the nodes which have count > 1.
//iii. Go through the map and assign address to all the nodes.
// Code:
ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)){
            return head;
        }
        ListNode *c = head;
        multimap<int,ListNode*> m;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
		
		//1.
        while(c){
            m.insert({c->val, c});
            c= c->next;
        }
        c=head;
		
		//2.
        while(c){
            if(m.count(c->val)>1){
                m.erase(c->val);
            }
            c=c->next;
        }
        c=dummy;
		
		//3.
        for(auto &g:m){
            c->next = g.second;
            c=c->next;
        }
        c->next = NULL;
        return dummy->next;
    }