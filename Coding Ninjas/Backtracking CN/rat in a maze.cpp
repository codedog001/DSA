/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<vector<int>> solution;

int b[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isValid(int r, int c, int n){
    if(r>=0 && c>=0 && r<n && c<n) return true;
    return false;
}

void printSolution(){
    for(auto &c:solution){
        for(auto &d:c){
            cout << d << " ";
        }
    }
    cout << endl;
}


void ratMazeHelper(int n, int row, int col){
    // Base case
    if(row == n-1 && col == n-1){
        solution[row][col] = 1;
        printSolution();
        solution[row][col] = 0;
        return;
    }

    //Place rat in all possible directions
    for(int i=0; i<4; i++){
        int newX = row + b[i][0];
        int newY = col + b[i][1];
        
        if(isValid(newX, newY, n) && a[newX][newY] == 1 && solution[newX][newY] == 0){
            solution[row][col] = 1;
            ratMazeHelper(n, newX, newY);
            solution[row][col] = 0;
        }
    }
}


int main() {
    int n;
    cin >> n;
	a.resize(n, vector<int>(n,0));
    solution.resize(n,vector<int>(n,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    ratMazeHelper(n, 0, 0);
}

