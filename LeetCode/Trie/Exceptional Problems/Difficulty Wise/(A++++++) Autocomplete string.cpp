//It prints all the words from that node.
void print(TrieNode* root, string op){
        if(!root) return;
        if(root->isTerminal) cout << op << endl;
        for(int i=0; i<26; i++){
            if(root->children[i]){
                string z = op + root->children[i]->data;
                print(root->children[i], z);
            }
        }
    }
    
    //It reaches the last node of pattern, then gives that node to print() to print all words from that node.
    void autoCompleteHelper(TrieNode* root, string p, string op){
        if(!root) return;
        if(p.size() == 0){
        	if(root->isTerminal) cout << op << endl;
            for(int i=0; i<26; i++){
                if(root->children[i]){
                    string y = op+ root->children[i]->data;
                    print(root->children[i], y);
                }
            }
            //This return is very important otherwise segementation fault.
            return;
        }
        
        int index = p[0] - 'a';
        op += p[0];
        autoCompleteHelper(root->children[index], p.substr(1), op);
    }

    void autoComplete(vector<string> ip, string p) {
        // Write your code here
        for(auto &c:ip) insertWord(c);
        string op = "";
        autoCompleteHelper(root, p, op);
    }