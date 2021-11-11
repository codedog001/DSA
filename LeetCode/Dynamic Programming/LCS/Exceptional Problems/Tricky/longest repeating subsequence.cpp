Logic: Find lcs of given string a with itself but leave the index when i==j
a: aabbcgge
b: aabbcgge (same as string a)

Normal LCS: aabbcgge
LCS (when a[i] == b[j] but i!= j): aabbgg, we will skip c and e, because they
will be skipped, other elements like 

a: i==0 j==0 -> skipped but comes when i==1 and j==0 -> then it gets selected.
Same is with b,g, while, c and e once skipped won't be encountered again.
Table:

   "" a a 
"" 0  0 0 ...
a  0  S 1 -> S - Skipped
a  0  1 0 ...

Code:
int LongestRepeatingSubsequence(string a){
		    string b = a;
		    int x = a.size(), y = b.size();
		    
		    int t[x+1][y+1];
		    for(int i=0; i<x+1; i++){
		        for(int j=0; j<y+1; j++){
		            if(i==0 || j==0) t[i][j] = 0;
		            else{
		                if(a[i-1] == b[j-1] && i != j) t[i][j] = 1 + t[i-1][j-1];
		                else t[i][j] = max(t[i-1][j], t[i][j-1]);
		            }
		        }
		    }
		    return t[x][y];
		}

