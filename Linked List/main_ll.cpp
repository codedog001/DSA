#include<iostream>
using namespace std;
#include "LinkedList.cpp"

Node* takeInput(){
    cout << "ENTER -1 TO QUIT" << endl;
    int data;
    cin >> data;
    Node *head = NULL;

    while(data!=-1){
        // Node h(data); -> wrong method, as soon as scope of while loop ends, the node will get deallocated.
        Node *n = new Node(data);
        n->next = NULL;

        if(head == NULL){ //Only enter address in head, if it is NULL.
            head = n;
        }
        else{
            Node *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp-> next = n;
        }
        cin >> data;
    }

    return head;
}

int main(){

    //Statically


    Node n1(10);
    Node n2(20);
    Node n3(50);

    n1.next = &n2;
    n2.next = &n3;

    Node *head = &n1;
    

    

    //Dynamically
    Node *n4 = new Node(60);
    Node *n5 = new Node(70);
    Node *n6 = new Node(80);

    n4->next = n5; //It won't be &n5, because n5 is address itself.
    n5->next = n6;
    n3.next = n4;


    // Node::print(head);

    // cout << &n1 << " " << head << endl;

    Node * h1 = takeInput();
    Node::print(h1);


}