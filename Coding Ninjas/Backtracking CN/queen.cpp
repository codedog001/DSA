#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
bool queenExists(int r, int c){
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

void nQueenHelper(int n, int row){
    if(row == n) {
        for(auto &c:a){
            for(auto &m:c){
                cout << m <<" ";
            }
        }
        cout << endl;
    	return;
	}
    //Find a safe pos in the n columns
    for(int i=0; i<n; i++){
        if(!queenExists(row, i)){
            a[row][i] = 1;
            nQueenHelper(n, row+1);
            a[row][i] = 0;
        }   
    }
}


int main(){
    
    // write your code here
    int n; 
    cin >> n;
    a.resize(n, vector<int>(n,0));
    nQueenHelper(n,0);
}