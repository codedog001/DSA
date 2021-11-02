#include<string>
#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* *children;
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

class Trie {
    //Datamembers
    TrieNode *root;
public:
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        return search(root, word);
    }
    
    bool startsWith(string prefix) {
        return startsWith(root, prefix);
    }
    
    private:
    void insert(TrieNode* root, string word){
        //base case
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        //Induction
        int index = word[0] - 'a';
        TrieNode* child;
        
        //If node already exists
        if(root->children[index] != NULL){
            child = root -> children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        //Hypothesis
        insert(child, word.substr(1));
    }
    
    bool search(TrieNode* root, string word){
        //Base Case
        if(word.size() == 0) return root->isTerminal;
        
        //Induction
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else return false;
        
        //Hypothesis
        return search(child, word.substr(1));
    }
    
    bool startsWith(TrieNode* root, string word){
        if(word.size()==0) return true;
        
        //Induction
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else return false;
        
        return startsWith(child, word.substr(1));
    }
};