#include<iostream>

using namespace std;

template <typename T>
class Queue{
    private:
    T * arr;
    int capacity;
    int nextIndex;
    int firstIndex;
    int size;

    public:
    Queue(){
        arr = new T[4];
        capacity = 4;
        nextIndex = 0; 
        firstIndex = 0;
        size = 0;
    }

    

    void enqueue(int ele){
        if(capacity == nextIndex){
            nextIndex = 0;
            if(firstIndex!=0 && nextIndex != firstIndex){
                arr[nextIndex] = ele;
                nextIndex++;
                return;
            }else if(firstIndex==0){
                cout << "OVERFLOW" << endl;
                return;
            }
        }else{
        arr[nextIndex] = ele;
        nextIndex++;
        }
        size++;
        return;
    }
    void printQueue(){
        cout << "QUEUE ELEMENTS: ";
        // for(int i=0; i<size; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        for(int i=firstIndex; i<capacity; i++){
            cout << arr[i] << " ";
        }
        if(firstIndex!=0){
            for(int i=0;i<nextIndex;i++){
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }


    T dequeue(){
        if(size ==0){
            cout << "UNDERFLOW" << endl;
            return 0;
        }
        T ele = arr[firstIndex];
        firstIndex++;
        size--;
        
        return ele;
    }

    T top(){
        if(isEmpty()){
            cout << "EMPTY"<<endl;
            return 0;
        }
        return arr[firstIndex];
    }

    

    int returnSize(){
        return size;
    }

    bool isEmpty(){
        if(nextIndex == 0){
            return true;
        }
        return false;
    }
};
