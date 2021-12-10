#include<bits/stdc++.h>
using namespace std;

//Helper Functions
bool isValidVertical(vector<string>& a, string word, int row, int col){
    if(row<0 || col <0 || row>=a.size() || col >= a.size()) return false;
    if(a[row][col] != '-' && a[row][col] != word[0]) return false;
    
    int spaceAvailable = 0;

    while(row < a.size()){
        if(a[row][col] == '+') break;
        spaceAvailable++;
        row++;
    }
    if(spaceAvailable != word.size()) return false;
    return true;
    
}

bool isValidHorizontal(vector<string>& a, string word, int row, int col){
    if(row<0 || col <0 || row>=a.size() || col >= a.size()) return false;
    if(a[row][col] != '-' && a[row][col] != word[0]) return false;
    
    int spaceAvailable = 0;
    while(col < a.size()){
        if(a[row][col] == '+') break;
        spaceAvailable++;
        col++;
    }
    if(spaceAvailable != word.size()) return false;
    return true;
}

bool setVertical(vector<string>& a, string word, int row, int col, vector<bool>& pos){
    for(int i=0; i<word.size(); i++){
        if(a[row+i][col] == '-'){
            a[row+i][col] = word[i];
            pos[i] = true;
        }
        else if(a[row+i][col] == word[i]) continue;
        else return false;
    }
    return true;
}

bool setHorizontal(vector<string>& a, string word, int row, int col, vector<bool>& pos){
    for(int i=0; i<word.size(); i++){
        if(a[row][col+i] == '-'){
            a[row][col+i] = word[i];
            pos[i] = true;
        }
        else if(a[row][col+i] == word[i]) continue;
        else return false;
    }
    return true;
}
void resetVertical(vector<string>& a, int row, int col, vector<bool>& pos){
    for(int i=0; i<pos.size(); i++){
        if(pos[i]) a[row+i][col] = '-';
    }
}
void resetHorizontal(vector<string>& a, int row, int col, vector<bool>& pos){
    for(int i=0; i<pos.size(); i++){
        if(pos[i]) a[row][col+i] = '-';
    }
}

void printSolution(vector<string>& a){
    for(auto &c:a){
        for(auto& d:c){
            cout << d;
        }
        cout << endl;
    }
    return;
}

void fun(vector<string>& a, vector<string> v, int index){
    //Base Case
    if(v.size() == index){
        printSolution(a);
        return;
    }
    //Place word vertically and horizontally
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(a[i][j] == '+') continue;
            if(isValidVertical(a,v[index], i, j)){
                //pos stores position of indexes which were changed by setVertical, to later reset them.
                vector<bool> pos(v[index].size(), false);
                if(setVertical(a,v[index], i, j, pos)){
                    fun(a,v,index+1);
                }
                resetVertical(a,i, j, pos);
            }
            if(isValidHorizontal(a,v[index], i, j)){
                //pos stores position of indexes which were changed by setHorizontal, to later reset them.
                vector<bool> pos(v[index].size(), false);
                if(setHorizontal(a,v[index], i, j, pos)){
                    fun(a,v,index+1);
                }
                resetHorizontal(a, i, j, pos);
            }
        }
    }
    
}
int main(){
    vector<string> a;
    for(int i=0; i<10; i++) {
        string x;
        cin >> x;
        a.push_back(x);
    }
    string word;
    cin >> word;
    word += ';';
    vector<string> v;
    
    int i=0, j=0;
    while(j<word.size()){
        if(word[j] != ';') j++;
        else if(word[j] == ';'){
            string s;
            s = word.substr(i, j-i);
            v.push_back(s);
            j++;
            i=j;
        }
    }
    
    fun(a, v, 0);
    // write your code here
    return 0;
}