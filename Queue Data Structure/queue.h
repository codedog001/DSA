#include<iostream>

using namespace std;

template <typename T>
class Queue{
    private:
    T * arr;
    int capacity;
    int nextIndex;

    public:
    Queue(){
        arr = new T[4];
        capacity = 4;
        nextIndex = 0; 
    }

    void shiftEle(){
        for(int i=1; i<nextIndex; i++){
            arr[i-1] = arr[i];
        }
    }

    void enqueue(int ele){
        if(capacity == nextIndex){
            T * newArr = new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[nextIndex] = ele;
        nextIndex++;
    }
    void printQueue(){
        cout << "QUEUE ELEMENTS: ";
        for(int i=0; i<nextIndex; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    T dequeue(){
        if(nextIndex ==0){
            cout << "UNDERFLOW" << endl;
            return 0;
        }
        T ele = arr[0];
        shiftEle();
        printQueue();
        nextIndex--;
        
        return ele;
    }

    T top(){
        if(isEmpty()){
            cout << "EMPTY"<<endl;
            return 0;
        }
        return arr[0];
    }

    

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        if(nextIndex == 0){
            return true;
        }
        return false;
    }
};
