#include "ourmap.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    OurMap<int>* map = new OurMap<int>();
    for(int i=0; i<1000; i++){
        string key = "abc";
        char c = '0' + i;
        key += c;
        int value = i+1;
        map->insert(key, value);
        cout << "Load Factor: " << map->getLoadFactor() << endl;
    }

    for(int i=0; i<1000; i++){
        string key = "abc";
        char c = '0' + i;
        key += c;
        cout << key << " : " << map->getVal(key) << endl;
    }
    delete map;
    cout << "ENDS" << endl;
}