#include<iostream>
using namespace std;
#include "LinkedList.cpp"



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

    Node * h1 = Node::takeInput();
    Node *h2 = Node::insert(h1);
    Node::print(h2); //Print is a static function.


}