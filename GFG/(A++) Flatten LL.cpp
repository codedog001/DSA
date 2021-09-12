Node *mergeLL(Node *l1, Node* l2){
    Node * dummy = new Node(0);
    Node * temp = dummy;
    
    while(l1 && l2){
        if(l1->data < l2->data){
            temp -> bottom = l1;
            l1 = l1->bottom;
        }
        else{
            temp -> bottom = l2;
            l2 = l2-> bottom;
        }
        temp = temp -> bottom;
    }
    temp -> bottom = l1 ? l1 : l2;
    return dummy -> bottom;
}
Node *flatten(Node *head)
{
   // Your code here
   if(!head || !(head->next)){
       return head;
   }
   head -> next = flatten(head->next);
   head = mergeLL(head,head->next);
   return head;
   
   
}