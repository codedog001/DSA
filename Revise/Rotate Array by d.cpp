//Approach 1: Store first d elements, shift n-d elements to left by d, and then push back d elements back.
#include<bits/stdc++.h>
using namespace std;
void rotate(int *inp, int d, int n)
{
    //Write your code here
    vector<int> a(d,0);
    for(int i=0; i<d; i++) a[i] = inp[i];
    for(int i=d; i<n; i++) inp[i-d] = inp[i];
    for(int i=n-d,j=0; i<n; i++,j++) inp[i] = a[j];

}

//Approach 2: Reverse whole array, then reverse a to a+n-d array, then reverse last d elements.
    
#include<bits/stdc++.h>
void rotate(int *a, int d, int n)
{
    //Write your code here
    reverse(a, a+n);
    reverse(a, a+n-d);
    reverse(a+n-d, a+n);

}
    