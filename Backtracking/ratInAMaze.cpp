#include<bits/stdc++.h>
using namespace std;

bool isPossible(int **maze, int **op, int n, int row, int col){
    if(row >= n || col >= n || maze[row][col] == 0 || op[row][col] == 1 || row < 0 || col < 0){
        return false;
    }
    return true;
}

void printop(int **op, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << op[i][j] << " ";
        }
    }
    cout << endl;
}

void hrat(int **maze, int **op, int n, int row, int col){
    
    //Base case
    if(row == n-1 && col == n-1){
        //Include this cell in solution
        op[row][col] = 1;
        printop(op,n);
        // op[row][col] = 0;
        return;
    }
    
    
    //Explore all possible paths:
    if(isPossible(maze,op,n,row,col)){
        op[row][col] = 1;
        hrat(maze,op,n,row-1,col);
        hrat(maze,op,n,row+1,col);
        hrat(maze,op,n,row,col-1);
        hrat(maze,op,n,row,col+1);
        op[row][col] = 0;
    }
    return;
}

int main() {

	// Write your code here
    int n;
    cin >> n;
    
    int **maze = new int*[n];
	for(int i=0;i<n;i++){
        maze[i] = new int[n];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> maze[i][j];
        }
    }
    
    int **op = new int*[n];
    
    for(int i=0;i<n;i++){
        op[i] = new int[n];
    }
    
    for(int i=0;i<n;i++){
        // memset(op[i],0,n*sizeof(int));
        for(int j=0; j<n; j++){
            op[i][j] = 0;
            // cout<<op[i][j] << endl;
		}
    }
    // printop(op,n);
    hrat(maze,op,n,0,0);
    for(int i=0;i<n;i++){
        delete[] maze[i];
        delete[] op[i];
	}
    
    delete[] maze;
    delete[] op;
}
