#include<bits/stdc++.h>
using namespace std;

int a[11][11];

bool ifPossible(int n, int row, int col){
    //Checking for Queen in Upper (row-1) Left (col-1) Diagonal
    for(int i=row-1,j=col-1; i>=0,j>=0; i--,j--){
        if(a[i][j] == 1){
            return false;
        } 
    }
    //Checking for Queen in Upper (row-1) Right (j+1) Diagonal
    for(int i=row-1,j=col+1; i>=0,j<n; i--,j++){
        if(a[i][j] == 1){
            return false;
        }
    }
    //Checking in upper column (row-1)
    for(int i = row-1; i>=0; i--){
        if(a[i][col] == 1){
            return false;
        }
    }

    return true;
}

void nQueenHelper(int n, int row){
    //Base case.
    if(row==n){
        //We have reached solution - Print the matrix.
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    

    //Check 0 to n me - jaha pe we are standing whether it is possible to place Q or not. Place then move to smaller problem.
    for(int j=0;j<n;j++){
        if(ifPossible(n,row,j)){
            a[row][j]  = 1;
            nQueenHelper(n,row+1); // - Jb yaha pe call waps ayega then we need to do 0 again here. Because agle row koi position possible nai hai, agr position to base case run ho jata.
            //TODO: NOTHING TODO, but THIS IS BACKTRACKING, so highlighted it:
            a[row][j] = 0;
        }
    }

    return;
}


void nQueen(int n){
    memset(a,0,11*11*sizeof(int));
    nQueenHelper(n,0);
}



int main(){
    
    // write your code here
    int n;
    cin >> n;
    nQueen(n);
}