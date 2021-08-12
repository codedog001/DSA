#include<iostream>

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    static void print(Node* head){ //Static fun because LL ko print krne ke lie, we don't need an object (a specific node).
        while(head != NULL){
            cout << head->data << endl;
            head = head->next;
        }
    }
};