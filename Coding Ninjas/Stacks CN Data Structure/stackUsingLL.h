#include<iostream>

class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Stack {
	// Define the data members
    Node * head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head = NULL;
    size =0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(head == NULL){
            return true;
        }
        return false;
    }

    void push(int element) {
        // Implement the push() function
        if(head == NULL){
            Node *newNode = new Node(element);
            head = newNode;
            size++;
        }else{
            Node *newOne = new Node(element);
            newOne -> next = head;
            head = newOne;
            size++;
            
        }
    }

    int pop() {
        // Implement the pop() function
        if(head == NULL){
            return -1;
        }
        Node *p = head;
        int datar = p->data;
        head = head -> next;
        delete p;
        size--;
        return datar;
    }

    int top() {
        // Implement the top() function
        if(head == NULL){
            return -1;
        }
        return head -> data;
    }
};