int findLen(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !(head->next) || k==0){
            return head;
        }
        int len = findLen(head);
        if(k%len == 0){ //Len =5 k=1500 -> Array will remain as it is after rotation
            return head;
        }else{
            
            int eleToShifFromEnd = k>len ? k%len : k; //if k=4, len =3 only 1 node needs to be shifted to head.
            
            ListNode *temp = NULL,* c= head;
            
            while(c && eleToShifFromEnd!=1){
                c=c->next;
                eleToShifFromEnd--;
            }
            temp = head;

            //Now move temp to node which will become head.
            while(c && c->next->next){
                c=c->next;
                temp=temp->next;
            }
            c=c->next;
            //Now temp stands on previous node of the node which will become head and c on last element.
            c->next = head;
            head = temp->next;
            temp->next = NULL;
            
            return head;
        }
        return NULL;
    }