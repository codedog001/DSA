#include<iostream>
using namespace std;

#include "queue.h"

int main(){
    Queue<int> *q = new Queue<int>();
    
    q->enqueue(0);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    q->enqueue(70);
    q->enqueue(80);
    q->enqueue(90);

    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    cout << q->top() << endl;

}