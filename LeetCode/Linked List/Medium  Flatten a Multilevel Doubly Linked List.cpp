/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* flatten_rec(Node * head){
        Node * curr = head, *tail = head;
        while(curr){
            Node *child = curr->child;
            Node *n = curr->next;
            
            if(curr->child){
                Node* rec_tail = flatten_rec(child);
                rec_tail -> next = n;
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;
                if(n!=NULL){
                    n->prev = rec_tail;
                }
                curr = rec_tail;
            }else{
                curr = n;
            }
            if(curr){
                tail = curr;
            }
        }
        return tail;
    }
    
    
    Node* flatten(Node* head) {
        if(head){
            flatten_rec(head);
        }
        return head;
    }
};