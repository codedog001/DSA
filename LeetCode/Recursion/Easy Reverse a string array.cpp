void rev(vector<char> &s, int index){
        if(s.size() == index){
            return;
        }
        char a = s[index+0];
        rev(s,index+1);
        s[s.size() -1 -index] = a;
        return;
    }
    void reverseString(vector<char>& s) {
        if(s.empty()){
            return;
        }
        int index = 0;
        rev(s,index);
        return;
    }