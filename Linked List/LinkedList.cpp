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

    static Node * insert(Node * head){

        cout << "INSERT at POS" << endl;
        cout << "Enter the position: " << endl;
        int pos=0,data=0;
        cin>>pos;
        cout << "Enter the data: " << endl;
        cin>>data;

        int count = 1;
        Node *m = new Node(data);

        //1. At 1st position
        if(pos==1){
            m->next = head;
            head = m;
            return head;
        }
        else{
            //1. Insertion in middle and end of LL
            Node *temp = head;
            while(count < pos-1 && temp!=NULL){
                count++;
                temp = temp->next;
            }
            m->next = temp->next;
            temp->next = m;
            return head;
        }
    }

    static Node* takeInput(){
    cout << "ENTER -1 TO QUIT" << endl;
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data!=-1){
        // Node h(data); -> wrong method, as soon as scope of while loop ends, the node will get deallocated.
        Node *n = new Node(data);
        n->next = NULL;

        if(head == NULL){ //Only enter address in head, if it is NULL.
            head = n;
            tail = n;
        }
        else{
            //Insert node at last
            //1. O(n) method
            // Node *temp = head;
            // while(temp->next!=NULL){
            //     temp = temp->next;
            // }
            // temp-> next = n;

            //2. O(1) method - Maintaining a tail pointer
            tail->next = n;
            tail = tail -> next;
            
        }
        cin >> data;
    }

    return head;
    }
};