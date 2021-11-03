void print(TrieNode* root, string op){
    if(!root) return;
    if(root->isTerminal) cout << op << endl;
    for(int i=0; i<26; i++){
        string t = op + root ->children[i]->data;
        print(root->childrn[i], t);
    }
}


void print(TrieNode* root){
    string op = "";
    print(root, op);
}

//P.S: Trie print all words from given node