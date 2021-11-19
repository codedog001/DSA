#include<climits>
0. Dynamic Programming
#include <cmath>
int countStepsToOne(int n){
	
    int a[n+1];
     
    a[1]=0; a[2]=a[3]=1;
   int b,c;
    for(int i=4 ;i<n+1;i++)
    {   
        b=c=n;
     
       if(i%2==0) b=a[i/2];
        if(i%3==0) c=a[i/3];
     
      a[i]=1+ min(a[i-1] ,min(b,c));
    }
return a[n];
}

2. Memoization
int countMinStepsToOnet(int n, int t[201])
{
	//Write your code here
    
    if(n<=1) return 0;
    int first = 0, second = INT_MAX, third = INT_MAX;
    
    if(t[n] != -1) return t[n];
    
    first = countMinStepsToOnet(n-1, t);
    if(n%2==0) second = countMinStepsToOnet(n/2, t);
    if(n%3==0) third = countMinStepsToOnet(n/3, t);
    
    return t[n] = 1 + min(min(first, second), third);
    
}

int countMinStepsToOne(int n){
    int t[201];
    for(int i=0; i<n+1; i++) t[i] = -1;
    return countMinStepsToOnet(n, t);
}