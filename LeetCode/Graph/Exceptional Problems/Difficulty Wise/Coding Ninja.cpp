//Problem name is coding ninja: Graph 1
//DFS + Backtracking used.

P.S: Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

E.g: 
I.P: 2 11
CXDXNXNXNXA
XOXIXGXIXJX

O.P: true

#include<bits/stdc++.h>
using namespace std;

string s = "CODINGNINJA";
int b[8][2]= {{0,1}, {0,-1}, {1,1}, {1,0}, {1,-1}, {-1,-1}, {-1,0}, {-1,1}};

bool isValid(int nr,int nc,int n,int m){
    if(nr>=0 && nc>=0 && nr<n && nc<m) return true;
    return false;
    
}

bool dfs(vector<vector<char>> &a, int row, int col, int ptr, vector<vector<bool>>& visited, int n, int m){
    //Base case
    if(ptr >= s.size()) {
        // cout << "T" << endl;
        return true;
    }
    bool found = false;
    visited[row][col] = true;

	for (int i = 0; i < 8; ++i){
		int newX = row + b[i][0];
		int newY = col + b[i][1];
        
        //Check if Dfs is possible on this point 
        if(isValid(newX, newY, n, m) && a[newX][newY] == s[ptr] && !visited[newX][newY]){
            // cout << "R" << endl;
           if(dfs(a, newX, newY, ptr+1, visited, n, m)) return true;;
        }
    }
    //If we crossed that for loop,that means we have to backtrack to previous position, becuase
    //if base condition we wouldn't have reached this point.
    //So, backtrack
    visited[row][col] = false;
    //Suppose 'D' search krna tha or 'O' ko khi nai mila, to wo loop se bahr aega, apne visited ko 
    //false krega, or false hi return krega, ab loop chl rha hai, to wo aage wale position pe 'O' find
    //karega, or agar koi naya pattern bnta hai isi current 'O' se to visited false hi hai, to koi
    //issue nai hoga, koi naya pattern isi 'O' se explore krne me.
    return found;
}

bool hasPath(vector<vector<char>> &a, int n, int m) {
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool foundPath = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == s[0]){
                foundPath = dfs(a, i, j, 1, visited, n, m);
                if(foundPath) break;
            }
        }
        if(foundPath) break;
    }
    
    return foundPath;
}