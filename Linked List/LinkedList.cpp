#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    static void print(Node* head){ //Static fun because LL ko print krne ke lie, we don't need an object (a specific node).
        cout << "Printing Linked List: "<< endl;
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};