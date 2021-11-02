//Used for pattern matching 
// The only difference is in search function, when we insert string, we insert all its suffixes also and search for them.

#include <string>
#include <vector>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    bool search(TrieNode* root, string word){
        if(word.size() == 0) return true;
        
        int index = word[0] - 'a';
        TrieNode * child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else return false;
        
        return search(child, word.substr(1));
    }
    
    bool search(string word){
        return search(root, word);
    }

    bool patternMatching(vector<string> a, string pattern) {
        // Write your code here
        for(auto & c:a){
            for(int i=0; i<c.size(); i++){
                insertWord(c.substr(i));
                if(search(pattern)) return true;
            }
            
        }
        return false;
    }
};