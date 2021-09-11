class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        
        public:
        Node(int key, int val){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
        
    };
    
    //Data Members of LRU cache
    
    //Dummy head and tail
    Node* head = new Node(0,0);
    Node* tail = new Node(-1,-1);
    
    unordered_map<int,Node*> m;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        //Now head and tail will be initialezed, i.e: head will point on tail.
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        Node* temp = NULL;
        
        //Retreive address of key if it exists in map
            if(m.find(key)!=m.end()){
                // cout << "K: " << key << " " << "VAL: " << m[key]->val << " ";
                Node *temp = m[key];
                int res = temp->val;
                deleteNode(temp);
                insertNode(key,res);
                m.erase(key);
                m[key] = head->next;
                
                return res;
            }
        
    
        
        return -1;
    
    }
    
    void deleteNode(Node* temp){
        if(temp && temp->next && temp->prev){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
    
    void insertNode(int key, int value){
        Node * newNode = new Node(key, value);
            
            //newNode will be inserted after dummy head
            newNode -> next = head->next;
            head -> next = newNode;
            newNode -> prev = head;
            newNode -> next -> prev = newNode;
            
            //Insert key and val
            newNode -> key = key;
            newNode -> val = value;
        
            //Create entry in map
            m[key] = newNode;
    }
    
    // void printLL(Node * head){
    //     Node* temp = head->next;
    //     while(temp!=NULL){
    //         cout<< "KEY: " <<temp -> key << "VAL: " << temp -> val << endl;
    //         temp = temp->next;
    //     }
    // }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
        //size is not a problem 
            
            Node * temp = NULL;
            temp = m[key];
            m.erase(key);
        
            
            //Delete node with this key from LL, and make it LRU node, i.e. put it next to head
            deleteNode(temp);
            
            
            //Insert node next to head
            insertNode(key,value);  
        }
        
        else{
            if(m.size()<cap){
                insertNode(key,value);
                return;
            }else {
            //The node adjacent to head is the node which has been used recently and the node followed by tail is the node which was least(earliest) used.
            
            //Delete previous node of tail
            int tem = tail -> prev -> key;
            deleteNode(tail->prev);
            
            //Delete key tem from map
            m.erase(tem);
            
            //Insert new node next to head
            //newNode will be inserted after dummy head
            insertNode(key,value);
            
        } 
        
    }
    
    }
};