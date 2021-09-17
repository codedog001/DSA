vector<vector<int>> res(numRows);
for(int i= 0; i<numRows; i++){
	//Create row of required size
	res[i].resize(i+1);
	//First and last element of all rows is 1.
	res[i][0] = res[i][i] = 1;

	//Now each element in pascal triangle is sum of res[i-1][j-1] i.e. element in previous column of previous row + res[i-1][j] i.e the same column of previous row.
	for(int j=1;j<i;j++){
		res[i][j] = res[i-1][j-1] + res[i-1][j];
	}
}
return res;
}