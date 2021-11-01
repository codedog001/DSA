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
            return hashCode % numBuckets;
        }

        int hashFunction(string key){
            int hashCode = 0, p = 37;
            for(int i=key.size()-1; i>=0; i++){
                //This will go out of int range very quickly
                // hashCode = key[i] * pow(p,i);

                //So, keep doing % numBuckets so that number remains small.
                hashCode += key[i] * (pow(p,i)%numBuckets);
                hashCode = hashCode % numBuckets;
            }
            
            int index =  compressionFunction(hashCode, numBuckets);
            return index;
        }

        public:
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
            MapNode<v>* head = buckets[bucketIndex];
            
            MapNode<v>* node = new MapNode<v>(key, value);
            node -> next = head;
            buckets[bucketIndex] = node;
            
            //Increment count
            count++;
            return;
        }

        v remove(string key){

        }

        v getVal(string key){

        }


        int size(){
            return count;
        }   
};




















