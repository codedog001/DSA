Time Complexity -> 2xO(NxM) -> ~O(NxM)
Space Complexity -> O(1)

void setZeroes(vector<vector<int>>& matrix) {
	bool hasZeroColZero=false; 
	int rows = matrix.size(), cols = matrix[0].size();
	
	//1st pass: 
	//1. Store information whether there is 0 in any row of matrix starting from first column onwards. - Where: In 0th cell of each row.
	//2. If 0th column contains a 0, then make hasZeroColZero = true. 

	for(int i=0; i<rows; i++){
		if(matrix[i][0] == 0) hasZeroColZero=true; //2 
		for(int j=1; j<cols; j++){ //1
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	//2nd Pass: Starting from the rightmost bottom corner, make the complete row and column = 0 where 0th cell of any row is 0. If hasZeroColZero is true then make 0 col as 0.
	for(int i=rows-1; i>=0; i--){
		for(int j=cols-1; j>=1; j--){

			//The matrix[0][j] part is the reason why we made matrix[0][j] = 0 in first pass whenver we found a 0.
			if(matrix[i][0] == 0 || matrix[0][j] == 0){
				matrix[i][j] = 0;
			}
		}
		if(hasZeroColZero==true) matrix[i][0] = 0;
	}
	return;
}