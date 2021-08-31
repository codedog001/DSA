#include<iostream>
using namespace std;

template<typename T>
class Stack{
    private:
    T *a;
    int nextIndex;
    int capacity;
    public:
    Stack(){
        a = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    bool isFull(){
        if(nextIndex == capacity){
            return true;
        }
        return false;
    }

    void push(int ele){
        if(isFull()){
            T *data = new T[capacity *2];
            for(int i=0; i<capacity; i++){
                data[i] = a[i];
            }
            delete[] a;
            a=data;
        }
        a[nextIndex] = ele;
        nextIndex++;
    }
    bool isEmpty(){
        if(nextIndex == 0){
            return true;
        }
        return false;
    }
    T pop(){
        if(isEmpty()){
            cout << "UNDERFLOW" <<endl;
            return 0;
        }
        nextIndex--;
        return a[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout << "Empty" << endl;
            return 0;
        }
        return a[nextIndex - 1];
    }
    int size(){
        return nextIndex;
    }
};