#include<iostream>
using namespace std;
#include<unordered_map>

int main(){
    unordered_map<string, int> m;
    m["abc"] =  2;
    // cout << "ABC: " << m["abc"] << endl;
    cout << "OLD GHI " << m["ghi"] << endl;
    // cout << "ABC: " << m.at("abc") << endl;
    // cout << "GHI: " << m.at("GHI") << endl;
    cout << "PRINTING MAP" << endl;
    for(auto &g:m) cout<< g.first << " " << g.second << endl;
    cout << "ENDS" << endl;
    cout << "GHI NEW " << m.at("ghi") << endl;
}