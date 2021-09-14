    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) {
                res += c;
                cout << "(: "<< opened << endl;
            }
            
            if (c == ')' && opened-- > 1){ 
                res += c;
                cout << "): "<< opened << endl;
            }
        }
        return res;
    }