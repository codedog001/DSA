Note: Here is the code to print longest common subsequence, it is not on Leetcode, but would have been a hard problem if it were on Leetcode, I guess.

string printLCS(string a, string b){
   int x = a.size(), y = b.size();
    int t[1001][1001];
    
   //Fill t
   lcs(a,b,x,y,t);
   
   int i=x, j=y;
   string res = "";
   while(i>0 && j>0){
       if(a[i-1] == b[j-1]){
           res.push_back(a[i-1]);
           --i;
           --j;
       }else{
           if(t[i-1][j] > t[i][j-1]) i--;
           else j--;
       }
   }
   reverse(res.begin(), res.end());
   return res;
}

void lcs(string& a, string& b, int x, int y, int t[][1001]){
    //Initialization
    for(int i=0; i<x+1; i++) t[i][0] = 0;
    for(int j=0; j<y+1; j++) t[0][j] = 0;
    
    //lcs 
    for(int i=1; i<x+1; i++){
        for(int j=1; j<y+1; j++){
            if(a[i-1] == b[j-1]) t[i][j] = 1 + t[i-1][j-1];
            else t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
}


int main() {
	string x = "acbcf", y = "abcdaf";
	string res = printLCS(x, y);
	cout << res << endl;
	return 0;
}