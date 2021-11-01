#include <string>
#include<cmath>
#include<iostream>
using namespace std;

template <typename v>

class MapNode{
    public:
//Datamembers
    string key;
    v value;
    MapNode* next;

    MapNode(string key, v value){
        this -> key = key;
        this -> value = value;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
    
};

template <typename v>
class OurMap{
    //Datamembers
    MapNode<v>** buckets;
    int count;
    int numBuckets;

    public:
        OurMap(){
            count = 0;
            numBuckets = 5;
            //Initialize array
            buckets = new MapNode<v>*[numBuckets];
            
            //Currently array has garbage addresses, so initialize those with NULL.
            for(int i=0; i< numBuckets; i++){
                buckets[i] = NULL;
            }
        }

        //Destructor
        //1. Delete linked list 
        //2. Delete whole array
        ~OurMap(){
            for(int i=0;i<numBuckets; i++){
                delete buckets[i];
            }
            delete []buckets;
        }

        private:

        int compressionFunction(int hashCode, int numBuckets){
            int ans = hashCode % numBuckets;
            return ans;
        }

        int hashFunction(string key){
            int hashCode = 0, p = 37;
            for(int i=key.size()-1; i>=0; i--){
                //This will go out of int range very quickly
                // hashCode = key[i] * pow(p,i);

                //So, keep doing % numBuckets so that number remains small.
                int multiplyFactor = pow(p,i);
                hashCode += key[i] * (multiplyFactor % numBuckets);
                hashCode = hashCode % numBuckets;
            }
            
            int index =  compressionFunction(hashCode, numBuckets);
            return index;
        }

        public:

        double getLoadFactor(){
            return (1.0*count)/numBuckets;
        }
        void rehash(){
            MapNode<v> ** temp = buckets;
            int oldNumBuckets = numBuckets;
            numBuckets *= 2;
            buckets = new MapNode<v>*[numBuckets];
            count = 0;

            //Assign null in new nodes of buckets array
            for(int i=0; i<numBuckets; i++){
                buckets[i] = NULL;
            }

            //Rehash all old nodes with new bucketsize
            for(int i=0; i<oldNumBuckets; i++){
                MapNode<v>* head = temp[i];
                while(head){
                    insert(head->key, head->value);
                    head = head -> next;
                }
            }

            //Don't delete whole array without deleting linked list 
            // delete [] temp;

            //Delete whole linked list first 
            for(int i=0; i<oldNumBuckets; i++){
                delete temp[i];
            }
            delete [] temp;
        }
        //Functions
        void insert(string key, v value){
            int bucketIndex = hashFunction(key);
            MapNode<v>* head = buckets[bucketIndex];
            //Case 1: If key already exists in map
            while(head){
                if(head -> key == key){
                    head->value = value;
                    return;
                }
                head = head -> next;
            }
            //Case 2: If key doesn't exist, insert new node as head of linked list, i.e. at first place.
            head = buckets[bucketIndex];
            
            MapNode<v>* node = new MapNode<v>(key, value);
            node -> next = head;
            buckets[bucketIndex] = node;
            
            //Increment count
            count++;

            //Check load factor = total nodes in whole array / total boxes (numBuckets)
            double loadFactor = (1.0 * count)/numBuckets;
            if(loadFactor > 0.7) rehash();
            return;
        }

        v remove(string key){
            int bucketIndex = hashFunction(key);
            MapNode<v>* head = buckets[bucketIndex];
            MapNode<v>* prev = NULL;

            while(head){
                if(head -> key == key){
                    v val = head->value;
                    //Case 0: If head->key, i.e. buckets[bucketIndex] -> key == key, i.e prev == NULL
                    if(prev == NULL){
                        if(head -> next) buckets[bucketIndex] = head -> next;
                        else buckets[bucketIndex] = NULL;
                    }
                    else {
                        if(head -> next) prev -> next = head -> next;
                        else prev-> next = NULL;
                    }

                    //There is problem with this statement: delete head, we have a recursive destructor, so jitni bhi node head -> next me hogi, wo sari bhi delete ho jaegi
                    //delete head;

                    //So, first make head->next = NULL, then call delete on head
                    head -> next = NULL;
                    delete head;

                    //Decrease count
                    count--;
                    return val;
                }
                prev = head;
                head = head -> next;
            }
            //Case 2: If key doesn't exist in map
            return 0;
        }

        v getVal(string key){
            int bucketIndex = hashFunction(key);
            MapNode<v>* head = buckets[bucketIndex];
            while(head){
                if(head -> key == key) return head -> value;
            }
            return 0;
        }


        int size(){
            return count;
        }   
};




















