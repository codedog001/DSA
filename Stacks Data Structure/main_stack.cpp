#include<iostream>
using namespace std;
#include "stackUsingArray.cpp"

int main(){
    Stack<char> *s = new Stack<char>;
    s->push(101);
    s->push(20);
    s->push(130);
    s->push(40);
    s->push(50);
    cout << "SIZE: " << s->size() << endl;
    // s->pop();
    // cout << ele << endl;
    // s->push(40);
    // cout << s->size() << endl;
    // cout << s->top() << endl;

    while(!s->isEmpty()){
        cout << "POPPING " << s->pop() << endl;
    }
    cout << "TOP: " << s->top() << endl;



}