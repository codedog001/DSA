#include<bits/stdc++.h>
using namespace std;


bool queenExists(vector<vector<int>>& a, int r, int c){
    //Search for queen in all 3 directions manually
    	int n = a.size();
        //1. Search upwards
        int m = r;
        while(m>=0){
            if(a[m][c] == 1) return true;
            m--;
        }
        
    	//2. Search Upper right
    	int z = r;
    	m=c;
    	while(m<n && z>=0){
            if(a[z][m] == 1) return true;
            z--;
            m++;
        }
    
    	//3. Search Upper left
    	z = r;
    	m=c;
    	while(m>=0 && z>=0){
            if(a[z][m] == 1) return true;
            z--;
            m--;
        }
    
    	return false;
}

bool queenSurvives(vector<vector<int>>& a, int r, int c){
    //Current r, c position is safe for q or not
    //dfs will search for queen in 8 directions of current point
    if(!queenExists(a, r, c)) return true;
    return false;
}

void nQueenHelper(int n, int row, vector<vector<int>>& a, int placedQueens){
    if(row > n) return;
    if(placedQueens == n) {
        for(auto &c:a){
            for(auto &m:c){
                cout << m <<" ";
            }
        }
        cout << endl;
    	return;
	}
    //Find a safe pos in the 4 columns
    for(int i=0; i<n; i++){
        if(queenSurvives(a, row, i)){
            a[row][i] = 1;
            nQueenHelper(n, row+1, a, placedQueens+1);
        }
        a[row][i] = 0;
    }
    
}

void nQueen(int n){
    for(int i=0; i<n; i++){
        vector<vector<int>> a(n, vector<int>(n, 0));
        a[0][i] = 1;
        nQueenHelper(n, 1, a, 1);
    }
}

int main(){
    
    // write your code here
    int n; 
    cin >> n;
    
    nQueen(n);
}