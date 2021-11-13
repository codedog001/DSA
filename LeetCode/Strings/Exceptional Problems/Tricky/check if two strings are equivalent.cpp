In first traversal of string a, add frequency of letters.
Then, traverse string b, and reduce the frequency of each letter from the vector, if any element in resultant vector is greater than 3, then return false, else true.

class Solution {
public:
    bool checkAlmostEquivalent(string a, string b) {
        vector<int> res(26,0);
        for (auto& c : a){
            int x = c - 97;
            res[x]++;
        }
        for (auto& d : b){
            int y = d - 97;
            res[y]--;
        }
        for (auto &e:res) {
            if (abs(e) > 3) return false;
        }
        return true;
    }
};