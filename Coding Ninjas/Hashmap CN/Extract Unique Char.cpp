#include<unordered_set>
string uniqueChar(string str) {
	// Write your code here
    unordered_set<char> s;
    string res = "";
    for(auto &c:str){
        if(s.find(c) == s.end()) {
            s.insert(c);
            res+=c;
        }
    }
    return res;
    
}