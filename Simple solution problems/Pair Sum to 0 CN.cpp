#include<unordered_map>
P.S: Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
E.g: 
I.P: 2 -2 -3 -2 2
O.P: 4

int pairSum(int *a, int n) {
	// Write your code here
    int res = 0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        int target = -a[i];
        if(m.find(target) != m.end()) res+= m[target];
        m[a[i]]++;
    }
    
    return res;
    
}